#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int main()
{
    int t;
    scanf("%d", &t);
    int c = 0;
    while(t--){
        c++;
        int n;
        scanf("%d", &n);
        int e[51];
        int i = 0;
        for(; i < n; i++){
            scanf("%d", &e[i]);
        }
        qsort(e, n, sizeof(int), cmp);
        int o[51];

        o[(n-1)/2] = e[n-1];
        int distleft = -1;
        int distright = n-1;
        int x = 1;
        while(distleft!=distright){
            int choose = 0;
            o[(n-1)/2+x] = e[++distleft];
            if(distleft==distright) break;
            o[(n-1)/2-x] = e[++distleft];
            if(distleft==distright) break;
            o[(n-1)/2+x+1] = e[--distright];
            if(distleft==distright) break;
            o[(n-1)/2-x-1] = e[--distright];
            x+=2;
        }
        i=0;
        int minDiff = o[0] - o[n-1];
        if(minDiff < 0) minDiff = minDiff * -1;

        int sumDiff = minDiff;
        i=0;
        for(; i < n-1; i++){
            int nextDiff = o[i] - o[i+1];
            if(nextDiff < 0) nextDiff = nextDiff * -1;
            sumDiff += nextDiff;
            if(minDiff > nextDiff) minDiff = nextDiff;
        }

        sumDiff -= minDiff;

        printf("Case %d: %d\n", c, sumDiff);
    }
    return 0;
}
