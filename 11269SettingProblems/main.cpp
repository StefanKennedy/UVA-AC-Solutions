#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct jpair{
    jpair();
jpair(int a, int b, int id) : first(a), second(b), id(id) {}
int first;
int second;
int id;
bool operator < (const jpair& other) const {
    return first < other.first;
}
};

struct ipair{
ipair();
ipair(int a,int b, int id) : first(a), second(b), id(id) {}
int first;
int second;
int id;
bool operator < (const ipair& other) const {
    return second < other.second;
}
};

int main()
{
    int n;
    while(cin >> n){
        vector<jpair> first;
        vector<ipair> second;

        int firsts[21];
        int seconds[21];
        for(int i = 0; i < n; i++){
            cin >> firsts[i];
        }
        for(int i = 0; i < n; i++){
            cin >> seconds[i];
        }
        for(int i = 0; i < n; i++){
            first.push_back(jpair(firsts[i], seconds[i], i));
            second.push_back(ipair(firsts[i], seconds[i], i));
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        set<int> seen;
        vector<pair<int, int> > doNow, doLater;
        int indexFirst = 0, indexSecond = 0;
        while(seen.size() < n){
            if(first[indexFirst].first < second[indexSecond].second){
                if(seen.find(first[indexFirst].id) != seen.end()){
                    indexFirst++;
                    continue;
                }
                seen.insert(first[indexFirst].id);
                doNow.push_back(pair<int, int>(first[indexFirst].first, first[indexFirst].second));
                while(seen.find(first[indexFirst].id) != seen.end()){
                    indexFirst++;
                }
            }else{
                if(seen.find(second[indexSecond].id) != seen.end()){
                    indexSecond++;
                    continue;
                }
                seen.insert(second[indexSecond].id);
                doLater.push_back(pair<int, int>(second[indexSecond].first, second[indexSecond].second));
                while(seen.find(second[indexSecond].id) != seen.end()){
                    indexSecond++;
                }
            }
        }

        // Start simulating that bad boy

        int factoryATime = 0;
        int factoryBTime = 0;

        for(int i = 0; i < doNow.size(); i++){
            factoryATime += doNow[i].first;
            factoryBTime = max(factoryATime + doNow[i].second, factoryBTime + doNow[i].second);
        }

        for(int i = doLater.size() - 1; i >= 0; i--){
            factoryATime += doLater[i].first;
            factoryBTime = max(factoryATime + doLater[i].second, factoryBTime + doLater[i].second);
        }

        cout << factoryBTime << endl;

    }
    return 0;
}
