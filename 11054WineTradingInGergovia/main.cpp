#include <iostream>
#include <vector>

using namespace std;

int main()
{

    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int> vi;
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;
            vi.push_back(c);
        }

        unsigned long long ans = 0;
        for(int i = 0; i < n; i++){
            int delta = vi[i];
            for(int j = i + 1; delta != 0 && j < n; j++){
                if(delta < 0){
                    if(vi[j] > 0){
                        //cout << "adding " << ((j-i)*(min(-1*delta, vi[j]))) << " for i = " << i << " j = " << j << endl;
                        ans += ((j-i)*(min(-1*delta, vi[j])));
                        int newDelta = min(0, delta+vi[j]);
                        vi[j] = max(0, vi[j]+delta);
                        delta = newDelta;
                    }
                }else {
                    if(vi[j] < 0){
                        //cout << "adding " << ((j-i)*(min(delta, -1*vi[j]))) << " for i = " << i << " j = " << j << endl;
                        ans += ((j-i)*(min(delta, -1*vi[j])));
                        int newDelta = max(0, delta+vi[j]);
                        vi[j] = min(0, vi[j] + delta);
                        delta = newDelta;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
