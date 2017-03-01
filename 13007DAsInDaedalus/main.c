#include <stdio.h>

int main() {
  int n, r;
  while(scanf("%d %d\n", &n, &r) == 2){
    long g = 0, l = 0;
    long ans = 0;
    while(r--){
      long b; long d;
      scanf("%ld %ld ", &b, &d);
      int i = 1;
      long t = 0;
      for(; i<n; i++){
        long a;
        scanf("%ld ", &a);
        b-=a;
        t+=a;
      }
      scanf("\n");
      long try = 1;
      long best = 0;
      while(try <= 10000){
        if(try<=b && try>best) best = try; 
        try = try * 10;
      }
      ans+=best;
      if(best >= d){
      ans -= d;
      }
    }
    printf("%ld\n", ans);
  }
  return 0;
}
