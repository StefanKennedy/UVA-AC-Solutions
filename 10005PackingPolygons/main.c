#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{
  double x;
  double y;
} pt;

int cross(pt a, pt b, pt o){
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int compare(const void* a, const void* b){
  pt pta = *((pt*)a);
  pt ptb = *((pt*)b);

  if(pta.x == ptb.x){
    return pta.y - ptb.y;
  }
  return pta.x - ptb.x;
}

int main(){
  while(1){
    int n;
    scanf("%d\n", &n);
    if(!n)break;
    pt pts[100];

  
    int i;
    for(i = 0; i < n; i++)
      scanf("%lf %lf\n", &(pts[i].x), &(pts[i].y));
  
    qsort(pts, n, sizeof(pt), compare);
  
    double r;
    scanf("%lf\n", &r);
  
    if(n==2){
      if(r*2 >= sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x)
                 + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y))){ 
        printf("The polygon can be packed in the circle.\n");
      }else{
        printf("There is no way of packing that polygon.\n");
      }
      continue;
    }

    int upper[100];
    int uppernext = 0;
    for(i = 0; i < n; i++){
      while(uppernext >= 2 && cross(
          pts[upper[uppernext - 2]],
          pts[upper[uppernext-1]],
          pts[i]) <= 0) uppernext--;
      upper[uppernext++] = i;
    }

    int lower[100];
    int lowernext = 0;
    for(i = n-1; i >= 0; i--){
      while(lowernext >= 2 && cross(
          pts[lower[lowernext - 2]],
          pts[lower[lowernext-1]],
          pts[i]) <= 0) lowernext--;
      lower[lowernext++] = i;
    }

    uppernext--;lowernext--;

    for(i = 0; i < uppernext; i++)
      lower[lowernext++] = upper[i];

    double max = 0;
    int j, k;
    for(i = 0; i < lowernext; i++)
      for(j = 0; j < lowernext; j++){
        if(i == j) continue;
        for(k = 0; k < lowernext; k++){
          if(k == i || k ==j) continue;
          double midx = (pts[lower[i]].x + pts[lower[j]].x) / 2;
          double midy = (pts[lower[i]].y + pts[lower[j]].y) / 2;

          double m = 
            -1 * 1 / ((pts[lower[i]].y - pts[lower[j]].y)
            / (pts[lower[i]].x - pts[lower[j]].x));
          double c = midy - m * midx;

          double midx2 = (pts[lower[i]].x + pts[lower[k]].x) / 2;
          double midy2 = (pts[lower[i]].y + pts[lower[k]].y) / 2;
          
          double m2 = -1 * 1 /
            ((pts[lower[i]].y - pts[lower[k]].y)
            / (pts[lower[i]].x - pts[lower[k]].x));
          double c2 = midy2 - m2 * midx2;

          double midx3 = (pts[lower[j]].x + pts[lower[k]].x) / 2;
          double midy3 = (pts[lower[j]].y + pts[lower[k]].y) / 2;

          double x = (c-c2)/(m2-m);
          double y = m*x + c;

          double dist = (pts[lower[i]].x - x) * (pts[lower[i]].x - x)
                        + (pts[lower[i]].y - y) *(pts[lower[i]].y - y);

          double distFromMid = (pts[lower[k]].x - midx) * (pts[lower[k]].x - midx)
            + (pts[lower[k]].y - midy) *(pts[lower[k]].y - midy);
          double radiusToMid = (pts[lower[i]].x - midx) * (pts[lower[i]].x - midx)
            + (pts[lower[i]].y - midy) *(pts[lower[i]].y - midy);
          if(distFromMid <= radiusToMid){
            if(distFromMid < dist) dist = radiusToMid;
          }

          distFromMid = (pts[lower[j]].x - midx2) * (pts[lower[j]].x - midx2)
            + (pts[lower[j]].y - midy2) *(pts[lower[j]].y - midy2);
          radiusToMid = (pts[lower[i]].x - midx2) * (pts[lower[i]].x - midx2)
            + (pts[lower[i]].y - midy2) *(pts[lower[i]].y - midy2);
          if(distFromMid <= radiusToMid){
            if(distFromMid < dist) dist = radiusToMid;
          }

          distFromMid = (pts[lower[i]].x - midx3) * (pts[lower[i]].x - midx3)
            + (pts[lower[i]].y - midy3) *(pts[lower[i]].y - midy3);
          radiusToMid = (pts[lower[j]].x - midx3) * (pts[lower[j]].x - midx3)
            + (pts[lower[j]].y - midy3) *(pts[lower[j]].y - midy3);
          if(distFromMid <= radiusToMid){
            if(distFromMid < dist) dist = radiusToMid;
          }

          if(dist > max) max = dist;
        }
        
      }
    max = sqrt(max);
    if(max <= r) printf("The polygon can be packed in the circle.\n");
    else printf("There is no way of packing that polygon.\n");
  }
  return 0;
}
