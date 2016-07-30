#include <iostream>
#include <stdlib.h>

using namespace std;

struct BigInt{
    const static int DIGITS = 100;
    int digits[DIGITS];
    BigInt(){
        BigInt(0);
    }
    BigInt(int init){
        for(int i = 0; i < DIGITS; i++){
            digits[i] = 0;
        }
        for(int i = 0; init > 0; init /= 10, i++){
            digits[i] = init % 10;
        }
    }
    void add(int toAdd){
        for(int i = 0; toAdd > 0; i++, toAdd/=10){
            int result = digits[i] + (toAdd % 10);
            if(result >= 10){
                toAdd+=10;
            }
            digits[i] = result % 10;
        }
    }
    BigInt addBI(BigInt toAdd){
        BigInt bi;
        bool carry = 0;
        for(int i = 0; i < DIGITS; i++){
            int result = toAdd.digits[i] + digits[i] + carry;
            bi.digits[i] = (result % 10);
            if(result >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
        }
        return bi;
    }
    void set(BigInt toSet){
        for(int i = 0; i < DIGITS; i++){
            digits[i] = toSet.digits[i];
        }
    }

    void print(){
        bool print = false;
        for(int i = DIGITS - 1; i >= 0; i--){
            if(digits[i] > 0){
                print = true;
            }
            if(print){
                cout << digits[i];
            }
        }
        if(!print){
            cout << 0;
        }
    }
};

int main()
{

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++){

        const int W = 10001;

        string x, z;

        cin >> x >> z;

        BigInt * dp = new BigInt[(W)*101];

        /*for(int i = 0; i <= x.length(); i++){
            for(int j = 1; j <= z.length(); j++){
                dp[j+(i*W)].set(0);
            }
        }*/

        for(int i = 0; i <= x.length(); i++){
            dp[i].set(1);
        }

        for(int i = 1; i <= z.length(); i++){
            for(int j = 1; j <= x.length(); j++){
                if(x[j-1]==z[i-1]){
                    dp[j + (i * W)].set(dp[(j-1)+(i*W)].addBI(dp[(j-1)+((i-1)*W)]));
                }else{
                    dp[j+(i*W)].set(dp[j+(i*W)-1]);
                }
            }
        }

        dp[x.length()+((z.length())*W)].print();
        cout << endl;

        /*for(int i = 1; i <= z.length(); i++){
            for(int j = 1; j <= x.length(); j++){
                dp[j + (i * W)].print();
                cout << " ";
            }
            cout << endl;
        }*/

        free(dp);

    }
    return 0;
}
