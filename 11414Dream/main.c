#include <stdio.h>
#include <stdlib.h>

int cmp (const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t > 0; t--){
        int n;
        scanf("%d", &n);
        int degrees[1000];
        int total = 0;
        int i =0;
        for(; i < n; i++){
            scanf("%d", &degrees[i]);
            total += degrees[i];
        }
        if(n==0){
            printf("Yes\n");
            continue;
        }
        if(n==1&&degrees[0]>0){
            printf("No\n");
            continue;
        }
        if(total % 2){
            printf("No\n");
            continue;
        }
        qsort(degrees, n, sizeof(int), cmp);
        i = 0;
        /*for(; i < n; i++){
            printf("%d", degrees[i]);
        }*/
        int k = 1;
        int possible = 1;
        for(;k<n;k++){
            i = 0;
            int sumd = 0;
            for(; i < k; i++){
                sumd += degrees[i];
            }
            int summin = 0;
            i = k;
            for(;i<n;i++){
                if(k <= degrees[i]){
                    summin += k;
                }else{
                    summin += degrees[i];
                }
            }
            if(sumd > k * (k - 1) + summin){
                possible = 0;
                break;
            }
        }
        if(possible){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
