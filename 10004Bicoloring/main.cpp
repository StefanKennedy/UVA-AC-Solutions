#include <iostream>
#include <vector>

using namespace std;

struct v{

    int visited = -1;
    vector<int> nexts;

};

int numVs, numLs;

vector<v> verts;

bool dfs(int nowOn){

    for(int i = 0; i < verts.at(nowOn).nexts.size(); i++){
        int checkingI = verts.at(nowOn).nexts.at(i);

        if(verts.at(checkingI).visited < 0){
            verts.at(checkingI).visited = 1-verts.at(nowOn).visited;

            if(!dfs(checkingI)){
                return false;
            }
        }
        else if(verts.at(checkingI).visited == verts.at(nowOn).visited){
            return false;
        }
    }

    return true;
}

int main()
{

    cin >> numVs;

    while(!cin.eof()){

        for(int i = 0; i < numVs; i++){
            verts.push_back(v());
        }

        cin >> numLs;

        if(numLs == 0 || numVs == 0){
            verts.clear();
            cin >> numVs;
            if(!cin.eof()){
                cout << "BICOLORABLE." << endl;
            }
            continue;
        }

        int startFrom, startTo;

        cin >> startFrom >> startTo;



        verts[startFrom].nexts.push_back(startTo);

        for(int i = 1; i < numLs; i++){
            int from, to;
            cin >> from >> to;
            verts[from].nexts.push_back(to);
        }

        verts.at(0).visited = 1;

        cout << (dfs(0) == 0 ? "NOT " : "") << "BICOLORABLE." << endl;

        verts.clear();
        cin >> numVs;
    }

    return 0;
}
