#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct bead{
    int start;
    int end;
};

typedef map<int, map<int, int> >::iterator itrator;
typedef map<int, int>::iterator itratorr;
typedef map<int, map<int, int> > bMap;

bool dfs(bMap * beadMap, int from, int colouredPath, string * s){

    cout << "Going to: " << colouredPath << "'s targets" << endl;

    // Go to all possibilities
    for(itratorr iter = (*beadMap)[colouredPath].begin(); iter != (*beadMap)[colouredPath].end(); iter++){
        int target = iter->first;
        if(iter->second > 0){
            (*beadMap)[colouredPath][target]-=1;
            (*beadMap)[target][colouredPath]-=1;
            dfs(beadMap, colouredPath, target, s);
            stringstream ss;
            ss << colouredPath;
            ss << " ";
            ss << target;
            ss << "\n";
            ss << *s;
            (*s) = ss.str();
        }
    }

    cout << "returning back" << endl;

    return true;

}

int main()
{

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){

        bMap beadMap;

        int N;
        cin >> N;

        cout << "Case #" << 1+i << endl;
        int start = 40;
        for(int j = 0; j < N; j++){
            int start, end;
            cin >> start >> end;
            if(beadMap[start][end] == 0){
                if(start == end){
                    beadMap[start][start] = 2;
                }else{
                    beadMap[start][end] = 1;
                    beadMap[end][start] = 1;
                }
            }else{
                beadMap[start][end]++;
                beadMap[end][start]++;
            }
            //cout << "increased " << start << " : " << end << " to " << beadMap[end][start] << endl;
        }

        int maxi = -1; int max = 0; bool flag = false;
        for(itrator iter = beadMap.begin(); iter != beadMap.end(); iter++){
            int num = 0;
            for(itratorr iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++){
                num += iter2->second;
            }
            if(num % 2 == 1){
                flag = true;
                break;
            }
            if(num > max){
                max = num;
                maxi = iter->first;
            }
        }
        if(flag){
                cout << "some beads may be lost" << endl << endl;
                continue;
        }

        string s = "";
        if(!dfs(&beadMap, -1, maxi, &s)){
                //cout << "some beads may be lost" << endl;
            }else{
                cout << s << endl;
            }

    }

    return 0;
}
