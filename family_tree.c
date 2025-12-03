#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#typedef Max 10001

typedef struct Node {
    char name[20];
    int depth;
    struct Node* leftChild;
    struct Node* rightSibling;
}Node;
Node *root = NULL;
Node *nodes[Max];
int n;

Node *find(char *name) {
    for (int i=0;i<n;i++) {
        if (strcmp(name,nodes[i] -> name)==0) {
            return nodes[i];
        }
    }
    return NULL;
}
Node *addNode(char *name) {
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name,name);
    p-> leftChild = NULL;
    p -> rightSibling = NULL;
    nodes[n] = p;
    n++;
    return p;
}
void makeChildParent(Node* child_node, Node* parent_node) {
    child_node -> rightSibling = parent_node -> leftChild;
}