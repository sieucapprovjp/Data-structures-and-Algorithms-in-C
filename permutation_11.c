#include <stdio.h>

int n;
int used[11];
int perm[11];

void backtrack(int pos) {
    if (pos > n) {
        for (int i = 1; i <= n; i++) {
            printf("%d", perm[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = 1;
            perm[pos] = i;
            backtrack(pos + 1);
            used[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    backtrack(1);
    return 0;
}
