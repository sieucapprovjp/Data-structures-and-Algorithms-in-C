#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    struct Node* next;
}Node;

Node* makeNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p -> value = x;
    p -> next = NULL;
    return p;
}
Node* top;
void initStack() {
    top = NULL;
}
int stackEmpty() {
    return top == NULL;
}
int pop() {
    if (stackEmpty()) return ' ';
    int x = top -> value;
    Node *p = top;
    top = top -> next;
    return x;
}
int push(int x) {
    Node* p = makeNode(x);
    p -> next = top;
    top = p;

}

int main() {
    char cmd[0];
    while (1) {
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0){
            break;
        }
        else if(strcmp(cmd,"PUSH")==0){
            push(v);
            int v; scanf("%d",&v);
        }
        else if(strcmp(cmd,"POP")==0){
            if(stackEmpty()){
                printf("NULL\n");
            }else{
                int v = pop();
                printf("%d\n",v);
            }
        }

    }
    return 0;
    }
}