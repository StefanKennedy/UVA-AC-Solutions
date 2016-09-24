#include <iostream>
#include <set>
#include <time.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(;t>0;t--){
        int n, k;
        cin >> n >> k;

        int blarg = n;

        for(int i = 0;;i++){
            int div = k;
            for(int j = 0; j < i; j++){
                div = div * k;
            }
            if(i%2 == 0){
                blarg -= n/div;
            }else{
                blarg += n/div;
            }
            if(n/div == 0){
                break;
            }
        }
        cout << blarg << endl;
    }
    return 0;
}
