#include <stdio.h>

void pm(int a,int c) {
    printf("%d -> %d\n",a,c);
}
void hanoi(int n,int a,int c) {
    if (n==1) {
        pm(a,c);
    }
    if (n>1) {
        int middle = 6-(a+c);
        hanoi(n-1,a,middle);
        pm(a,c);
        hanoi(n-1,middle,c);
    }
}
int main() {
    int n,a,c;
    scanf("%d %d %d",&n,&a,&c);
    hanoi(n,a,c);
}