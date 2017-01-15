#include <stdlib.h>
#include <stdio.h>



typedef struct{
  double x;
  double y;
} point;

int compare(const void* a, const void* b){
  point pa = *(point*)a;
  point pb = *(point*)b;
  if(pa.x != pb.x)
    return pa.x - pb.x;
  return pa.y - pb.y;
}

double crs(point a, point b, point o){
  return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int main() {
  while(1){
    int n;
    scanf("%d\n", &n);

    if(!n) break;

    point pts[51];
    int i;
    for(i = 0; i < n; i++){
      scanf("%lf %lf\n", &pts[i].x, &pts[i].y);
    }

    qsort(pts, n, sizeof(point), compare);

    int sign = crs(pts[0], pts[1], pts[2]);
    if(sign == 0) sign = 1;

    int u[51];
    int ui = 0;
    for(i = 0; i < n; i++){
      while(ui >= 2 && sign * crs(pts[u[ui-2]], pts[u[ui-1]], pts[i]) < 0) ui--;
      u[ui++] = i;
    }

    int l[51];
    int li = 0;
    for(i = n-1; i >= 0; i--){
      while(li >= 2 && sign * crs(pts[l[li-2]], pts[l[li-1]], pts[i]) < 0) li--;
      l[li++] = i;
    }

    ui--;li--;

    if(ui+li < n) printf("Yes\n");
    else printf("No\n");
    
  }
  return 0;
}
