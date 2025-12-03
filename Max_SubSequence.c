#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long cur = LLONG_MIN, best = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        if (cur == LLONG_MIN) cur = x;         // khởi tạo ở phần tử đầu tiên
        else cur = (cur + x > x) ? (cur + x) : x;
        if (cur > best) best = cur;
    }
    printf("%lld\n", best);
    return 0;
}
