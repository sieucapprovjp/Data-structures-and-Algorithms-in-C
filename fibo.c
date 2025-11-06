#include <stdio.h>
#define Max 1000
#define MOD 1000000007
int M[Max];
void init(int n) {
    M[0] = 0;
    M[1] = 1;
    for (int i=2;i<=n;i++) {
        M[i]=0;
    }
}
int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        if (M[n]== 0 && n != 0) {
            M[n] = (fibo(n-1) + fibo(n-2))% MOD;
        }
    }
    return M[n];
}
int main() {
    int n;
    scanf("%d",&n);
    init(n);
    printf("%d",fibo(n));
}