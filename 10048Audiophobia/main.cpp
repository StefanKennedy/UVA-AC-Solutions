#include <iostream>
#include <string.h>
#include <limits.h>

#define INT_MAX 2147483647

using namespace std;

int main()
{

    for(int i = 1; i > 0; i++){
        int crossings, streets, queries;
        int paths[101][101];
        cin >> crossings >> streets >> queries;

        for(int i = 0; i <= crossings; i++){
            for(int j = 0; j <= crossings; j++){
                paths[i][j] = INT_MAX;
            }
        }

        if(crossings + streets + queries == 0){
            break;
        }

        if(i > 1){
            cout << endl;
        }
        cout << "Case #" << i << endl;

        for(int i = 0; i < streets; i++){
            int a, b, d;
            cin >> a >> b >> d;
            paths[a][b] = paths[b][a] = d;
        }

        /*for(int i = 0; i <= crossings; i++){
            for(int j = 0; j <= crossings; j++){
                cout << paths[i][j] << " ";
            }
            cout << endl;
        }*/


        for(int k = 0; k <= crossings; k++){
            for(int i = 0; i <= crossings; i++){
                for(int j = 0; j <= crossings; j++){
                    paths[i][j] = paths[j][i] = min(paths[i][j], max(paths[i][k], paths[k][j]));
                }
            }
        }

        for(int i = 0; i < queries; i++){
            int start, end;
            cin >> start >> end;

            int output = paths[start][end];
            if(output == INT_MAX){
                cout << "no path" << endl;
            }else{
                cout << output << endl;
            }
        }
    }

    return 0;
}
