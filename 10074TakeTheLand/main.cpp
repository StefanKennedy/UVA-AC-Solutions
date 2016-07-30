#include <iostream>

using namespace std;

int main()
{
    int w, h;
    cin >> h >> w;
    while(w + h > 0){

        int matrix[100][100];

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> matrix[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            matrix[i][0] = (matrix[i][0] ? 0 : 1);
            for(int j = 1; j < w; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                }else{
                    matrix[i][j] = matrix[i][j-1] + 1;
                }
            }
        }

        int max = 0;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){

                int rW = matrix[i][j];
                for(int i2 = i, mult = 1; i2 < h; i2++, mult++){

                    if(matrix[i2][j] < rW){
                        rW = matrix[i2][j];
                    }
                    if(rW * mult > max){
                        max = rW * mult;
                    }
                }

            }
        }

        cout << max << endl;

        cin >> h >> w;

    }

}
