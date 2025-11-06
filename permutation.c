#include <stdio.h>

int perm(char str[],int index,int end) {
    if (index == end) {
        str[end] = '\0';
        printf("%s\n",str);
        return;
    }
    str[index] = '0';
    perm(str,index+1,end);
    str[index] = '1';
    perm(str,index+1,end);
}
int main() {
    int n;
    scanf("%d",&n);
    char str[n+1];
    perm(str,0,n);
}