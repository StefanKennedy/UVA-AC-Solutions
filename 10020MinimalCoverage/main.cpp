#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
    int a;
    int b;
    line(int a, int b): a(a), b(b) { }
};

bool line_sort(line a, line b){
    if(a.a == b.a){
        return a.b < b.b;
    }
    return a.a < b.a;
}

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        int M;
        cin >> M;

        vector<line> v;
        int a, b;
        while(true) {
            cin >> a >> b;
            if(a == 0 && b == 0){
                break;
            }
            line l(a, b);
            v.push_back(l);
        }

        stable_sort(v.begin(), v.end(), line_sort);

        vector<line> ans;
        ans.clear();

        int count = 0;
        line choice(0, 0);
        for(int j = 0, dist = 0; j < v.size(); j++){

            if(v[j].a > dist){
                if(choice.b >= M){ // Will be added to vector once we leave for
                    break;
                }
                if(choice.a != 0 || choice.b != 0){
                    ans.push_back(choice);
                }
                dist = choice.b;
                if(v[j].a > dist){
                    ans.clear();
                    choice = line(0, 0);
                    break;
                }
            }
            if(v[j].b > choice.b){
                choice = v[j];
            }
            if(j == v.size() - 1 && choice.b < M){
                choice = line(0, 0);
            }
        }

        if(choice.a != 0 || choice.b != 0){
            ans.push_back(choice);
        }

        if(i > 0){
            cout << endl;
        }

        if(ans.size() == 0 || (ans[ans.size() - 1].b < M)){
            cout << 0 << endl;
            continue;
        }

        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].a << " " << ans[i].b << endl;
        }
    }

    return 0;
}
