#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct iipair {
    iipair(int l, int r) : left(l), right(r) {};
    int left;
    int right;

    bool operator < (const iipair& other) const {
        if(right == other.right){
            return left > other.left;
        }
        return right > other.right;
    }
};

int main()
{
    int casee = 1;
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<iipair> vii;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            vii.push_back(iipair(a, b));
        }

        sort(vii.begin(), vii.end());

        int maxtime = 0;
        int curtime = 0;
        for(int i = 0; i < n; i++) {
            maxtime = max(curtime + vii[i].left + vii[i].right, maxtime);
            curtime = curtime + vii[i].left;
        }

        cout << "Case " << casee << ": " << maxtime << endl;
        casee++;
    }
    return 0;
}
