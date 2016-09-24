#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int main()
{
    int *factors = malloc(sizeof(int) * 5000001);

    int s = 1;
    for(; s <= 5000000; s++){
        int u = s;
        for(; u <= 5000000; u+=s) {
            factors[u]++;
        }
    }

    int *mice = malloc(sizeof(int) * 5000001);

    int *o = malloc(sizeof(int) * 5000001);
    int t;
    scanf("%d", &t);
    while(t--){

        int a, b;
        scanf("%d %d", &a, &b);
        int n = b-a+1;
        int i = a;
        int blarg = 0;
        for(; i <= b; i++){
            mice[i-a] = factors[i];
        }
        qsort(mice, n, sizeof(int), cmp);
        o[n/2] = mice[0];
        i = 1;
        int x = 1;
        int maxDiff = 0;
        while(1){
            if(n/2-i<0) break;
            o[n/2 - i] = mice[x];
            if(mice[x] - o[n/2 - i + 1] > maxDiff) maxDiff = mice[x] - o[n/2 - i + 1];
            if(n/2+i>=n) break;
            o[n/2 + i] = mice[x+1];
            if(mice[x + 1] - o[n/2 + i - 1] > maxDiff) maxDiff = mice[x + 1] - o[n/2 + i - 1];
            i++;
            x+=2;
        }
        if(o[0] - o[n-1] > maxDiff) maxDiff = o[0] - o[n-1];
        if(o[n-1] - o[0] > maxDiff) maxDiff = o[n-1] - o[0];

        i = 0;
        printf("%d\n", maxDiff);
    }
    free(mice);
    free(factors);
    free(o);
    return 0;
}
