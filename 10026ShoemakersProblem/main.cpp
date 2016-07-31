#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct t{
    t(): r(0), i(0) {};
    t(float r, int i): r(r), i(i){}
    float r;
    int i;
};

bool cmpr(t a, t b){
    return a.r > b.r;
}

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        int M;
        cin >> M;

        t res[1000];

        for(int j = 0; j < M; j++){

            float d;
            float c;

            cin >> d >> c;
            res[j] = t(c/d, j+1);

        }

        std::vector<t> v;
        v.assign(res, res + M);

        std::stable_sort(v.begin(), v.end(), cmpr);

        for(int j = 0; j < M; j++){
            cout << v[j].i;
            if(j < M - 1){
                cout << " ";
            }
        }

        if(i < N - 1)
        cout << endl;
        cout << endl;

    }

    return 0;
}
