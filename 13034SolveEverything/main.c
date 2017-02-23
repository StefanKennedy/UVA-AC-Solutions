#include <stdio.h>

int main(){
  int t;
  scanf("%d\n", &t);
  int c = 0;
  while(t--){
    int q, w, e, r, t, y, u, i, o, p, a, s, d;
 scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d", &q, &w, &e, &r, &t, &y, &u, &i, &o, &p, &a, &s, &d);
    int ans = q == 0 || w == 0 || e == 0 || r == 0 || t == 0 || y == 0 || u == 0 || i == 0 || o == 0 || p == 0 || a == 0 || s == 0 || d == 0;
    if(ans == 1){
      printf("Set #%d: No\n", ++c);
    } else {
      printf("Set #%d: Yes\n", ++c);
    } 
  }
}
