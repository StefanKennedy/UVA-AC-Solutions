#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(;t>0;t--){
        int n;
        int mins;
        int m;
        cin >> n >> mins >> m;
        vector<int> times;
        int mod = m%n;
        for(;m>0;m--){
            int next;
            cin >> next;
            times.push_back(next);
        }
        sort(times.begin(), times.end());
        int ans = 0;
        int curtime = 0;
        for(int i = mod == 0 ? n-1 : mod-1; i< times.size(); i+=n){
            curtime = max(times[i]+(mins*2), curtime+(mins*2));
            ans++;
        }
        cout << curtime - mins << " " << ans<< endl;
    }
    return 0;
}
