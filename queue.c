//https://hustack.soict.ai/programming-contest/student-view-contest-problem-detail/GENERAL_CONTEST/QUEUE_SIM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
}Node;

Node *head = NULL;
Node *rear = NULL;

void push(int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    if (rear == NULL) {
        head = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
void pop() {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    Node *temp = head;
    int value = temp -> value;
    head = head -> next;
    if (head == NULL) {
        rear = NULL;
    }
    free(temp);
    printf("%d\n",value);
}
void freeQueue() {
    Node *current = head;
    if (current != NULL) {
        Node *temp = current;
        current = current -> next;
        free(temp);
    }
}

int main() {
    char cmd[20];
    int value;
    while (1) {
        scanf("%s",cmd);
        if (strcmp(cmd,"#")==0) {
            break;
        }
        else if (strcmp(cmd,"PUSH")==0) {
            scanf("%d",&value);
            push(value);
        }
        else if (strcmp(cmd,"POP")==0) {
            pop();
        }
    }
    freeQueue();
    return 0;
}
