#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while(true){
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0){
            break;
        }
        vector<int> heads;
        vector<int> soldiers;
        for(;n>0;n--){
            int next;
            cin >> next;
            heads.push_back(next);
        }
        for(int i = 0; i < m; i++){
            int next;
            cin >> next;
            soldiers.push_back(next);
        }
        sort(heads.begin(), heads.end());
        sort(soldiers.begin(), soldiers.end());

        int soldier = 0;
        int ans = 0;
        bool doomed = false;
        for(int i = 0; i < heads.size(); i++){
            bool found = false;
            for(;soldier < m;soldier++){
                if(soldiers[soldier] >= heads[i]){
                    found=true;
                    ans+=soldiers[soldier];
                    soldier++;
                    break;
                }
            }
            if(!found){
                doomed = true;
                break;
            }
        }

        if(doomed)
            cout << "Loowater is doomed!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
