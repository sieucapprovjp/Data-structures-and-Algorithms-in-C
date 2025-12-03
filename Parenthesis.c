#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000005
char s[MAX_N];
char stack[MAX_N];
int top = -1;

bool match(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}
void push(char c) {
    stack[++top] = c;
}
bool isEmpty() {
    return top ==-1;
}
char peek() {
    return stack[top];
}
void pop() {
    if (top >= 0)top--;
}

bool check(char* str) {
    top = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        } else {
            if (isEmpty()) return false;
            char currentOpen = peek();
            pop();
            if (!match(currentOpen,str[i])) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    if (scanf("%s", s)!= 1) return 0;
    if (check(s)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}