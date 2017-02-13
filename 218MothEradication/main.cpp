#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct pt{
  double x;
  double y;

  bool operator < (const pt& other) const {
    if(x == other.x){
      return y < other.y;
    }
    return x < other.x;
  }
};

double cross(pt a, pt b, pt o) {
  return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double dist(pt a, pt b){
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  int n;
  int unclephilv2 = 0;
  while(1){
    scanf("%d\n", &n);
    if(!n) break;
    if(unclephilv2++ > 0) printf("\n");

    vector<pt> pts;
    for(int i = 0; i < n; i++){
      pt a;
      scanf("%lf %lf\n", &a.x, &a.y);
      pts.push_back(a);
    }

    if(n == 1){
      printf("Region #%d:\n", unclephilv2);
      printf("(%0.1lf,%0.1lf)-(%0.1lf,%0.1lf)\n", pts[0].x, pts[0].y, pts[0].x, pts[0].y);
      printf("Perimeter length = 0.00\n");
      continue;
    }

    sort(pts.begin(), pts.end());

    vector<pt> upper;
    for(int i = 0; i < n; i++){
      while(upper.size() > 1 && 
            cross(upper[upper.size()-2], upper[upper.size()-1], pts[i]) >= 0){ upper.pop_back(); }
      upper.push_back(pts[i]);
    }

    vector<pt> lower;
    for(int i = n-1; i >= 0; i--){
      while(lower.size() > 1 && 
            cross(lower[lower.size()-2], lower[lower.size()-1], pts[i]) >= 0){ lower.pop_back(); }
      lower.push_back(pts[i]);
    }

    /*printf("All pts: \n");
    for(int i = 0; i < n; i++){
      printf("%lf %lf\n", pts[i].x, pts[i].y);
    }*/

    upper.pop_back();
    lower.pop_back();

    printf("Region #%d:\n", unclephilv2);
    double total = 0;
    for(int i = 0; i < upper.size(); i++){
      printf("(%0.1lf,%0.1lf)-", upper[i].x, upper[i].y);
      if(i>0) total += dist(upper[i], upper[i-1]);
    }

    for(int i = 0; i < lower.size(); i++){
      printf("(%0.1lf,%0.1lf)-", lower[i].x, lower[i].y);
      if(i>0) total += dist(lower[i], lower[i-1]);
    }
    printf("(%0.1lf,%0.1lf)\n", upper[0].x, upper[0].y);
    total += dist(lower[0], upper[upper.size() - 1]);
    total += dist(lower[lower.size() - 1], upper[0]);
    printf("Perimeter length = %0.2lf\n", total);
  }
}
