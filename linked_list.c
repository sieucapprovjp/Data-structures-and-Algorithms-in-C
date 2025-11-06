#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node *header = NULL;
Node* MakeNode(int v) {
    Node *p = (Node*)malloc(sizeof(Node));
    p -> value =v;
    p-> next = NULL;
    return p;
}
Node *addFirst(Node* header, int v) {
    Node *p = MakeNode(v);
    p -> next = header;
    return p;
}
Node *addLast(Node *header,int v) {
    if (header == NULL) {
        return MakeNode(v);
    }
    h ->next = addLast(h -> next,v);
    return h;
}
Node *addBefore(Node *header,int u,int v) {
    if (header == NULL) {
        return NULL
    }
    if (header-> value == v) {
        Node *q = MakeNode(u);
        q -> next = header;
        return q;
    }
    header -> next = addBefore(header -> next,u,v);
    return h;
}
Node *addAfter(Node *header,int u,int v) {
    if ( header == NULL) {
        return NULL;
    }
    if (header -> key== v) {
        Node *q = MakeNode(u);
        q->next= header-> next;
        header-> next = q;
        return header;
    }
    header-> next = addAfter(header -> next,u,v);
}
Node *removeNode(Node *head,int v) {
    if (head == NULL) return NULL;
    if (head-> value==v) {
        Node* tmp = head;
        head = head -> next;
        free(tmp);
        return h;
    }
    head -> next = removeNode(head->next,v);
}
Node *reverse(Node *h) {
    Node *p = h;
    Node *pp = NULL;
    Node *np = NULL;
    while (p != NULL) {
        np = p->next;
        pp = p;
        p = np;
    }
    return pp;
}
