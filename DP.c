#include <stdio.h>
#define N 100001
int a[N];
int n;
int F[N];
int ans;
int select_problem;
int start_i[N];
void solve() {
    F[1] = a[1];
    start_i[1] =1;
    ans = F[1];
    select_problem = 1;
    for (int i=2;i<=n;i++) {
        if (F[i-1] >0) {
            F[i] = F[i-1] + a[i];
            start_i[i] = start_i[i-1];
        }
        else {
            F[i] = a[i];
            start_i[i] = i;
        }
        if (F[i] > ans) {
            ans = F[i];
            select_problem = i;
        }
    }
    printf("Day con lon nhat: %d\n",ans);
    printf("Diem bat dau %d -> %d",start_i[select_problem],select_problem);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    solve();

}