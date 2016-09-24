#include <iostream>

using namespace std;

int main()
{
    while(true){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        //cout << "on to next test case " << n << endl;
        int whatIsAtOriginal[501];
        int whereIsOriginal[501];
        for(int i = 0; i < n; i++){
            cin >> whatIsAtOriginal[i+1];
            //cout << "reading " << whatIsAtOriginal[i+1] << endl;
            whereIsOriginal[whatIsAtOriginal[i+1]] = i+1;
        }
        int minAns = n;
        for(int j = 0; j < n; j++){
            int whatIsAt[501];
            int whereIs[501];
            for(int i = 1; i <= n; i++){
                whatIsAt[i] = whatIsAtOriginal[i];
                whereIs[i] = whereIsOriginal[i];
            }
            int ans = 0;
            for(int i = 1; i <= n; i++){
                int want = ((i-1+j)%n)+1;
                if(whatIsAt[i] == want){
                    continue;
                }
                whatIsAt[whereIs[want]] = whatIsAt[i];
                whereIs[whatIsAt[i]] = whereIs[want];
                whatIsAt[i] = want;
                ans++;
            }
            minAns = min(ans, minAns);
            ans = 0;
            for(int i = 1; i <= n; i++){
                whatIsAt[i] = whatIsAtOriginal[i];
                whereIs[i] = whereIsOriginal[i];
            }
            for(int i = 1; i <= n; i++){
                int want = n-((i-1+j)%n);
                //cout << want << " == " << whatIsAt[i] << " ";
                if(whatIsAt[i] == want){
                    //cout << "match ";
                    continue;
                }
                whatIsAt[whereIs[want]] = whatIsAt[i];
                whereIs[whatIsAt[i]] = whereIs[want];
                whatIsAt[i] = want;
                ans++;
            }
            //cout << endl;
            minAns = min(ans, minAns);
        }
        cout << minAns << endl;
    }
    return 0;
}
