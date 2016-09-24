#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(;t>0;t--){
        int n;
        cin >> n;
        int whereShouldItBe[10001];
        int whatIsHere[10001];
        int whatShouldBeHere[10001];
        int whereIsIt[10001];
        for(int i = 0;i<n;i++){
            int l, r;
            cin >> l >> r;
            //cout << "Where should it be " << l << " = " << i+1 << endl;
            whereShouldItBe[l] = i + 1;
            whatIsHere[i+1] = r;
            whatShouldBeHere[i+1] = l;
            whereIsIt[r] = i + 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            //cout << "What is at " << i << "? " << whatIsHere[i] << endl;
            /*if(i==whereShouldItBe[whatIsHere[i]]){
                //cout << "Not Swapping " << i << " with " << whereShouldItBe[whatIsHere[i]] << " found " << whatIsHere[i] << endl;
                continue;
            }*/
            //cout << "Swapping from " << i << " to " << whereShouldItBe[whatIsHere[i]] << endl;
            /*int temp = whatIsHere[whereShouldItBe[whatIsHere[i]]];
            whatIsHere[whereShouldItBe[whatIsHere[i]]] = whatIsHere[i];
            whatIsHere[i] = temp;*/
            if(whatIsHere[i] == whatShouldBeHere[i]){
                continue;
            }
            whatIsHere[whereIsIt[whatShouldBeHere[i]]] = whatIsHere[i];
            whereIsIt[whatIsHere[i]] = whereIsIt[whatShouldBeHere[i]];
            whatIsHere[i] = whatShouldBeHere[i];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
