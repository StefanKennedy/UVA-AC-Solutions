#include <iostream>

using namespace std;

void flipUp(int grid[102][102], int N, int y, int x){
    int tmp = grid[x][y];
    grid[x][y] = grid[N-1-x][y];
    grid[N-1-x][y] = tmp;
}

void flipRight(int grid[102][102], int N, int y, int x){
    int tmp = grid[x][y];
    grid[x][y] = grid[x][N-1-y];
    grid[x][N-1-y] = tmp;
}

void flipDia(int grid[102][102], int N, int y, int x){
    int tmp = grid[x][y];
    grid[x][y] = grid[y][x];
    grid[y][x] = tmp;
}

void flipInvDia(int grid[102][102], int N, int y, int x){
    int tmp = grid[x][y];
    grid[x][y] = grid[N-1-y][N-1-x];
    grid[N-1-y][N-1-x] = tmp;
}

int flip(int grid[102][102], int N, int y, int x, int type){
    switch(type){
        case 1:
            flipUp(grid, N, y, x);
            break;
        case 2:
            flipRight(grid, N, y, x);
            break;
        case 3:
            flipDia(grid, N, y, x);
            break;
        case 4:
            flipInvDia(grid, N, y, x);
            break;
    }

}

int main()
{
    int M;
    cin >> M;

    for(int i = 0; i < M; i++){

        int N;
        cin >> N;

        int rings[102][102];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> rings[i][j];
            }
        }

        int numRings = ((N+1)/2);

        int moves[51][52];

        for(int i = 1; i <= numRings; i++){
            cin >> moves[i][0];
            for(int j = 1; j <= moves[i][0]; j++){
                cin >> moves[i][j];
            }
        }

        for(int i = 1; i <= numRings; i++){
            for(int j = 1; j <= moves[i][0]; j++){
                i--;
                switch(moves[i+1][j]){
                    case 1:
                        for(int k = i; k < N - i; k++){
                            flip(rings, N, k, i, moves[i+1][j]);
                        }
                        for(int k = i + 1; k < numRings; k++){
                            flip(rings, N, i, k, moves[i+1][j]);
                        }
                        for(int k = i + 1; k < numRings; k++){
                            flip(rings, N, N-i-1, k, moves[i+1][j]);
                        }
                        break;
                    case 2:
                        for(int k = i + 1; k < N - i; k++){
                            flip(rings, N, i, k, moves[i+1][j]);
                        }
                        for(int k = i; k < numRings; k++){
                            flip(rings, N, k, i, moves[i+1][j]);
                        }
                        for(int k = i + 1; k < numRings; k++){
                            flip(rings, N, k, N-i-1, moves[i+1][j]);
                        }
                        break;
                    case 3:
                        for(int k = i + 1; k < N - i - 1; k++){
                            flip(rings, N, i, k, moves[i+1][j]);
                        }
                        for(int k = i; k < N - i; k++){
                            flip(rings, N, k, N-1-i, moves[i+1][j]);
                        }
                        break;
                    case 4:
                        for(int k = i + 1; k < N - i; k++){
                            flip(rings, N, i, k, moves[i+1][j]);
                        }
                        for(int k = i; k < N - i; k++){
                            flip(rings, N, k, i, moves[i+1][j]);
                        }
                        break;
                }

                i++;
            }
        }



        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << rings[i][j];
                if(j < N - 1){
                    cout << " ";
                }
            }
            cout << endl;
        }

    }

    return 0;
}
