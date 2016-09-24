#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
    return (*(int*)b - *(int*)a);
}

int main()
{
    while(1){
        int n;
        scanf("%d", &n);
        if(!n){
            break;
        }
        int degrees[10000];
        int i = 0;
        int sum = 0;
        for(; i < n; i++){
            scanf("%d", &degrees[i]);
            sum += degrees[i];
        }
        if(n==1 && degrees[0] > 0){
            printf("Not possible\n");
            continue;
        }
        if(sum % 2){
            printf("Not possible\n");
            continue;
        }
        qsort(degrees, n, sizeof(int), cmp);
        int k = 1;
        int possible = 1;

        for(; k < n; k++){
            int sumd = 0;
            i = 0;
            for(; i < k; i++){
                sumd += degrees[i];
            }
            int kkminus1 = k * (k - 1);
            int sum_min_dk = 0;
            i=k;
            for(;i<n;i++){
                if(degrees[i] < k){
                    sum_min_dk += degrees[i];
                }else{
                    sum_min_dk += k;
                }
            }
            if(sumd > kkminus1 + sum_min_dk){
                possible = 0;
                break;
            }
        }

        if(possible){
            printf("Possible\n");
        } else {
            printf("Not possible\n");
        }
    }
    return 0;
}
