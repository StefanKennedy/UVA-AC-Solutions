#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        vector<int> coins;
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;
            coins.push_back(c);
        }
        sort(coins.begin(), coins.end());

        int total = 0; int ans = 0;
        for(int i = 0; i < coins.size()-1; i++){
            if (total + coins[i] < coins[i+1]) {
                ans++;
                total += coins[i];
            }
        }
        ans++;
        cout << ans << endl;
    }

    return 0;
}
