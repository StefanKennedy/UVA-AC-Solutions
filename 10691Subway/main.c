#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double pi = 3.14159265359;
const double npi = -3.14159265359;

typedef struct{
    double left;
    double right;
} line;

double pyth(int x, int y)
{
    return sqrt(x*x+y*y);
}

int cmp(const void* a, const void* b){
    line *lineA = (line*)a;
    line *lineB = (line*)b;
    if(lineA->right == lineB->right){
        return ((lineA->left - lineB->left) > 0) * 2 - 1;
    }
    return ((lineA->right - lineB->right) > 0) * 2 - 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--){
        int n, d;
        scanf("%d %d", &n, &d);
        line blargs[400];
        int norails = 1;
        int i = 0;
        for(;i<n;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            double hypo = pyth(x, y);
            if (hypo <= d){
                blargs[i].left = -9999;
                blargs[i].right = -9999;
                continue;
            }
            norails = 0;
            double directAngle = atan2(y, x);
            double maxAngleVariation = asin(d / hypo);
            blargs[i].left = directAngle - maxAngleVariation;
            blargs[i].right = directAngle + maxAngleVariation;
            if(blargs[i].right > pi){
                blargs[i].right -= 2*pi;
                blargs[i].left -= 2*pi;
            }

        }
        if(norails){
            printf("0\n");
            continue;
        }
        i = 0;
        qsort(blargs, n, sizeof(line), cmp);
        for(;i<n;i++){
            blargs[n+i].left = blargs[i].left + 2*pi;
            blargs[n+i].right = blargs[i].right + 2*pi;
        }
        int ans = n;
        int j = 0;
        for(;j<n;j++){
            double furthestAngle = -10;
            i = 0;
            int blarg = 0;
            for(;i<n;i++){
                if(blargs[i+j].left == -9999 && blargs[i+j].right == -9999){
                    continue;
                }
                if(blargs[i+j].left - 0.000000000001 > furthestAngle){
                    blarg++;
                    furthestAngle = blargs[i+j].right;
                }
            }
            if(blarg < ans) ans = blarg;
        }
        printf("%d\n", ans);
    }
    return 0;
}
