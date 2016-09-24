#include <stdio.h>
#include <stdlib.h>

int dfs(char * target, char * progress, int n, int p, int ca, char leftMustBe, char mustBe, char lastMustBe, char lastLastMustBe){

    if(p==n){
        return 1;
    }

    int i = 0;
    for(;i<8;i++){
        if((p==n-1)&&((((i&2)>0)!=lastMustBe)||((i&1)!=lastLastMustBe))){
            continue;
        }
        if(((ca&(1<<i))>0) == (*(target + p)) - '0'){
            if(((i&4)>0) == leftMustBe){

                if(((i&2)>0) == mustBe){
                    if(dfs(target, progress, n, p+1, ca, mustBe, (i&1), lastMustBe, lastLastMustBe)){
                        return 1;
                    }

                }

            }

        }
    }
    return 0;
}

int dfsGO(char * target, char * progress, int n, int p, int ca){
    int i = 0;
    for(; i<4;i++){
        if(dfs(target, progress, n, p, ca, (i&2)>0, i&1, (i&2)>0, i&1)){
            printf("REACHABLE\n");
            return 1;
        }
    }
    printf("GARDEN OF EDEN\n");
}

int main()
{
    int ca, n;
    char a[33];
    while(scanf("%d %d %s", &ca, &n, &a) == 3){
        char progress[33];
        progress[n] = progress[0];
        dfsGO(a, progress, n, 0, ca);


    }
    return 0;
}
