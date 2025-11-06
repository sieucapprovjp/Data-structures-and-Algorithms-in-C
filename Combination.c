#include <stdio.h>

int binary(char str[],int index,int end) {
    if (index == end) {
        for (int i=0;i<end;i++) {
            if (str[i] == str[i-1] && str[i]=='1') {
                return;
            }
        }
        str[end] = '\0';
        printf("%s\n",str);
        return 1;
    }
    str[index] = '0';
    binary(str,index+1,end);
    str[index] = '1';
    binary(str,index+1,end);
}
int main() {
    int n;
    scanf("%d",&n);
    char a[n+1];
    binary(a,0,n);
}