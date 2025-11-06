#include <stdio.h>
#define X 100
int n,M;
int x[X];

void linear(int i,int remain) {
    if (i ==n) {
        x[i] = remain;
    }
    if (x[i]>0) {
        for (int j =1;j<=n;j++) {
            printf("%d ",x[j]);
        }
        printf("\n");
    }
    else {
        for (int k=1;k<=remain-n+i;k++) {
            x[i] = k;
            linear(i+1,remain-k);
        }
    }
}

int main() {
    scanf("%d %d",&n,&M);
    linear(1,M);
    return 0;
}
