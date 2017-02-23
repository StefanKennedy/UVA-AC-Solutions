#include <stdlib.h>
#include <stdio.h>

int main() {
  int t;
  while(scanf("%d\n", &t) == 1){
    int a, b, c, d, e;
    scanf("%d %d %d %d %d\n", &a, &b, &c, &d, &e);
    printf("%d\n", (a==t)+(b==t)+(c==t)+(d==t)+(e==t));
  }
  return 0;
}
