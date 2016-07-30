#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int M, N;

struct position{

    int m, n, d, c, s;
    position(){
        m = n = d = c = s = 0;
    };
    position(int m2, int n2, int d2, int c2, int s2){
        m = m2;
        n = n2;
        d = d2;
        c = c2;
        s = s2;
    }
    bool equals(position p){
        //cout << "(" << m << "==" << p.m << ")&&(" << n << "==" << p.n << ")&&(" << c << "==" << p.c << ")" << endl;
        return ((m==p.m)&&(n==p.n)&&(c==p.c));
    }

    position turn(bool right){return position(m, n, (d + (right ? 1 : 3)) % 4, c, s+1);}
    position forward(){
        if(d == 0){
            if(m - 1 < 0){
                return *this;
            }
        //cout << "Moving forward" << endl;
            return position(m - 1, n, d, (c + 1) % 5, s+1);
        }else if(d == 1){
            if(n + 1 >= N){
                return *this;
            }
        //cout << "Moving forward" << endl;
            return position(m, n + 1, d, (c + 1) % 5, s+1);
        }else if(d == 2){
            if(m + 1 >= M){
                return *this;
            }
        //cout << "Moving forward" << endl;
            return position(m + 1, n, d, (c + 1) % 5, s+1);
        }else{
            if(n - 1 < 0){
                return *this;
            }
        //cout << "Moving forward" << endl;
            return position(m, n - 1, d, (c + 1) % 5, s+1);
        }
    }
};

struct pt{
    int m, n;
    pt(int a, int b){
        m = a;
        n = b;
    }
};

int main()
{

    M = N = 1;
    int caseNum = 0;

    while(M + N > 0){

        caseNum++;
        cin >> M >> N;

        if(M+N==0){
            break;
        }

        if(caseNum > 1){
            cout << endl;
        }
        cout << "Case #" << caseNum << endl;

        char grid[26][26];
        bool v[26][26][5][5];

        //cout << v[1][1][1][1] << endl;

        position s, t;

        for(int m = 0; m < M; m++){
            for(int n = 0; n < N; n++){
                cin >> grid[m][n];
                if(grid[m][n] == 'S'){
                    s = position(m, n, 0, 1, 0); // Start location, begins looking North on Green
                }else if(grid[m][n] == 'T'){
                    t = position(m, n, -1, 1, 0); // Target logation, on Green, directioj doesnt matter
                }
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < 5; j++){
                        v[m][n][i][j] = 0;
                    }
                }
            }
        }

        queue<position> q;
        q.push(s);

        bool found = 0;

        while(q.size() > 0){

            position next = q.front(); int m = next.m, n = next.n, d = next.d, c = next.c;
            q.pop();

            //if(grid[m][n] == '#')
                //cout << "On a hash" << endl;
            if(grid[m][n] == '#' || v[m][n][d][c]){
                continue;
            }
            //cout << "In [" << m << "][" << n << "] looking " << (d == 0 ? "North" : (d == 1 ? "East" : (d == 2 ? "South" : "West"))) << " with colour: " <<
            //(c == 0 ? "White" : (c == 1 ? "Green" : (c == 2 ? "Black" : (c==3 ? "Red" : "Red")))) <<  " visited? " << v[m][n][d][c] << endl;
            if(next.equals(t)){
                //cout << q.empty() << " ?" << endl;
                found = 1;
                cout << "minimum time = " << next.s << " sec" << endl;
                break;
            }

            v[m][n][d][c] = 1;

            q.push(next.forward());
            q.push(next.turn(true));
            q.push(next.turn(false));

        }
        if(!found)
            cout << "destination not reachable" << endl;
    }

    return 0;
}
