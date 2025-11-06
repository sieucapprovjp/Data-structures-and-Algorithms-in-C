#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 1000
#define MOD 1000000007
long long M[Max][Max];
void init(int k,int n) {
    for (int i=0;i<=k;i++) {
        for (int j=0;j<=n;j++) {
            M[i][j] = 0;
        }
    }
}
long long C_k_n(int k,int n) {
    if (k == 0||k==n) {
        return 1;
    }
    if (M[k][n] ==0) {
        M[k][n] = (C_k_n(k-1,n-1) + C_k_n(k,n-1)) %MOD;
    }
    return M[k][n] ;
}

int main() {
    int k, n;
    scanf("%d %d",&k,&n);
    init(k,n);
    printf("%d",C_k_n(k, n));
    return 0;
}
