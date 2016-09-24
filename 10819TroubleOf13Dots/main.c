#include <stdio.h>
#include <stdlib.h>

int ind(int i, int j){
    return i * 101 + j;
}

int main()
{
    const int m_max = 10200;
    int * dp = malloc(sizeof(int) * (10201 * 101 + 1));
    int m, n;
    while(scanf("%d %d", &m, &n) == 2){
        int i = 0;
        int p[100], f[100];
        for(;i<n;i++){
            scanf("%d %d", &p[i], &f[i]);
        }

        i = 0;
        for(;i<=m_max;i++){
            int j = 0;
            for(;j<=100;j++) *(dp + ind(i, j)) = -1;
        }
        i = 0;
        for(;i<=100;i++){
            *(dp+ind(0,i)) = 0;
        }

        i = 0;
        int max = 0;
        int maxCost = 0;
        int maxBelowN = 0;
        for(;i<n;i++) {
            int j = 0;
            for(;j<=m+200;j++){
                int next_price = j + p[i];
                if(i>0 && *(dp+ind(j, i-1))>=0 && *(dp+ind(j, i-1)) > *(dp+ind(j, i))){
                    *(dp+ind(j, i)) = *(dp+ind(j, i-1));
                }
                if(*(dp+ind(j, i))>=0 && next_price <= m + 200){
                    if(f[i] + (*(dp+ind(j,i))) > *(dp+ind(next_price,i+1))) *(dp+ind(next_price,i+1)) = f[i] + (*(dp+ind(j,i)));
                    if(f[i] + (*(dp+ind(j,i))) > max && next_price > 2000){
                        max = f[i] + (*(dp+ind(j,i)));
                        maxCost = next_price;
                    }
                    if(j + p[i] <= m && f[i] + (*(dp+ind(j,i))) > maxBelowN){
                        maxBelowN = f[i] + (*(dp+ind(j,i)));
                        if(maxBelowN > max){
                            maxCost = next_price;
                            max = maxBelowN;
                        }
                    }
                }
            }
        }
        if(maxCost > 2000){
            printf("%d\n", max, maxCost);
        }else{
            printf("%d\n", maxBelowN);
        }

    }
    free(dp);
    return 0;
}
