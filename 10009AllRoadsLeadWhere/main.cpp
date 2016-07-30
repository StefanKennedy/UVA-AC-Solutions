#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct city{
    int level = -1;
    string path = "";
    char pathToken = 'R';
    vector<city*> nextCities;
};

void setLevel(city *nextCity, int newLevel, string path){
    (*nextCity).level = newLevel;
    path = path + (*nextCity).pathToken;
    (*nextCity).path = path;
    for(int i = 0; i < (*nextCity).nextCities.size(); i++){
        setLevel((*nextCity).nextCities.at(i), newLevel + 1, path);
    }
}

int main()
{
    int nTests;
    cin >> nTests;

    for(int h = 0; h < nTests; h++){

        int nRoads, nQueries;
        cin >> nRoads >> nQueries;

        map<char, city> cities;

        for(int i = 0; i < nRoads; i++){
            string fromCity, toCity;
            cin >> fromCity >> toCity;

            if(cities.find(fromCity[0]) == cities.end()){
                cities.insert(pair<char, city>(fromCity[0], city()));
                cities[fromCity[0]].pathToken = fromCity[0];
            }

            if(cities.find(toCity[0]) == cities.end()){
                cities.insert(pair<char, city>(toCity[0], city()));
                cities[toCity[0]].pathToken = toCity[0];
            }

            cities[fromCity[0]].nextCities.push_back(&cities[toCity[0]]);

        }

        setLevel((&cities['R']), 0, "");
        cities['R'].path = "R";

        for(int i =0 ;i < nQueries; i++){
            string cityA, cityB;
            cin >> cityA >> cityB;

            if(cityA[0] == cityB[0]){
                cout << cityA[0] <<endl;
            }

            for(int j = 0; j < cities[cityA[0]].path.length() || j < cities[cityB[0]].path.length(); j++){
                if(cities[cityA[0]].path.length() == j || cities[cityB[0]].path.length() == j || cities[cityA[0]].path[j] != cities[cityB[0]].path[j]){
                    for(int k = cities[cityA[0]].path.length(); k > j; k--){
                        cout << cities[cityA[0]].path[k - 1];
                    }
                    cout << cities[cityA[0]].path[j - 1];
                    for(int k = j; k < cities[cityB[0]].path.length(); k++){
                        cout << cities[cityB[0]].path[k];
                    }
                    cout << endl;
                    break;
                }
            }
        }
        if(h < nTests - 1){
            cout << endl;
        }
    }

    return 0;
}
