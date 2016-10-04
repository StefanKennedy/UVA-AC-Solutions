#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>

#define xy pair<int, int>

using namespace std;

int visited[1000];

int dfs(int column, int (*rgraph)[1000], int n){
    for(int i = 0; i < n; i++){
        if(!visited[i] && !rgraph[i][column]){
            visited[i] = 1;
            dfs(i, rgraph, n);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<xy> beacons;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            beacons.push_back(make_pair(x, y));
        }

        vector<xy> peaks;
        vector<int> radii;
        for(int i = 0; i < m; i++){
            int x, y, r;
            cin >> x >> y;
            cin >> r;
            peaks.push_back(make_pair(x, y));
            radii.push_back(r);
        }

        sort(beacons.begin(), beacons.end());

        int (*rgraph)[1000] = new int[1000][1000];
        for(int i = 0; i < n; i++){
            vector<pair<double, int> > angles;
            for(int j = i + 1; j < n; j++){
                double angle = atan2(beacons[j].second - beacons[i].second, beacons[j].first - beacons[i].first);
                angles.push_back(make_pair(angle, j));
            }
            sort(angles.begin(), angles.end());

            for(int j = 0; j < m; j++){
                double angle = atan2(peaks[j].second - beacons[i].second, peaks[j].first - beacons[i].first);
                int xDiff = peaks[j].first - beacons[i].first, yDiff = peaks[j].second - beacons[i].second;
                double radiusAngle = asin(radii[j] / sqrt(xDiff * xDiff + yDiff * yDiff));
                double lower_angle = angle - radiusAngle, upper_angle = angle + radiusAngle;
                int first_angle = lower_bound(angles.begin(), angles.end(), make_pair(lower_angle, -1)) - angles.begin();
                for(int k = first_angle; k < angles.size() && angles[k].first <= upper_angle; k++){

                    xy vector_beacons = make_pair(beacons[angles[k].second].first - beacons[i].first, beacons[angles[k].second].second - beacons[i].second);
                    xy vector_peak = make_pair(beacons[angles[k].second].first - peaks[j].first, beacons[angles[k].second].second - peaks[j].second);

                    if((vector_beacons.first * vector_peak.first) + (vector_beacons.second * vector_peak.second) > 0){
                        rgraph[i][angles[k].second] = 1;
                        rgraph[angles[k].second][i] = 1;
                    }
                }
            }
        }

        memset(visited, 0, sizeof(visited));

        int num_riders = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                dfs(i, rgraph, n);
                num_riders++;
            }
        }

        cout << num_riders << endl;
    }
    return 0;
}
