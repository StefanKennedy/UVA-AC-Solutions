#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x;
  double y;
} pt;

double cross(pt a, pt b, pt o){
  return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int compare(const void* a, const void* b){
  if((*(pt*)a).x == (*(pt*)b).x){
    return (*(pt*)a).y - (*(pt*)b).y;
  }
  return (*(pt*)a).x - (*(pt*)b).x;
}

int main(){
  int tilenum = 0;
  while(1){
    int n;
    scanf("%d\n", &n);
    if(!n)break;

    pt pts[101];
    int i;
    for(i = 0; i < n; i++){
      scanf("%lf %lf\n", &pts[i].x, &pts[i].y);
    }

    double cost = 0;
    int j = n-1;
    for(i = 0; i < n; i++){
      cost += (pts[j].x*pts[i].y)-(pts[j].y*pts[i].x);
      j = i;
    }

    qsort(pts, n, sizeof(pt), compare);

    int lower[101];
    int lowernext = 0;
    for(i = 0; i < n; i++){
      while(lowernext >= 2
            && cross(pts[lower[lowernext-2]], pts[lower[lowernext-1]], pts[i]) <= 0){
        lowernext--;
      }
      lower[lowernext++] = i;
    }

    int upper[101];
    int uppernext = 0;
    for(i = n - 1; i >= 0; i--){
      while(uppernext >= 2
            && cross(pts[upper[uppernext-2]], pts[upper[uppernext-1]], pts[i]) <= 0){
        uppernext--;
      }
      upper[uppernext++] = i;
    }

    uppernext--;lowernext--;

    cost /= 2;
    if(cost < 0) cost = cost * -1;


    for(i = 0; i < lowernext; i++)
      upper[uppernext++] = lower[i];

    double costBigger = 0;
    j = uppernext-1;
    for(i = 0; i < uppernext; i++){
      costBigger += (pts[upper[j]].x*pts[upper[i]].y)-(pts[upper[j]].y*pts[upper[i]].x);
      j = i;
    }
    costBigger /= 2;
    if(costBigger < 0) costBigger = costBigger * -1;

    printf("Tile #%d\n", ++tilenum);
    printf("Wasted Space = %0.2lf %\n", 100 * (1 - cost / costBigger));
    printf("\n");
  }
  return 0;
}
