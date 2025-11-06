#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Segment;

int cmp(const void *x, const void *y) {
    Segment *s1=(Segment *)x;
    Segment *s2=(Segment *)y;
    if (s1->b!=s2->b)
        return s1->b - s2->b;
    return s1->a - s2->a;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Segment *seg = (Segment *)malloc(n * sizeof(Segment));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &seg[i].a, &seg[i].b);
    }
    qsort(seg, n, sizeof(Segment), cmp);
    int count = 0;
    int last_end = -1;
    for (int i = 0; i < n; i++) {
        if (seg[i].a > last_end) {
            count++;
            last_end = seg[i].b;
        }
    }
    printf("%d\n", count);
    free(seg);
    return 0;
}