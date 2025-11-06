#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* createNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}

int exists(Node *head, int val) {
    for (Node *p = head; p; p = p->next)
        if (p->val==val)
            return 1;
    return 0;
}

void addLast(Node **head, int val) {
    if (exists(*head, val)) return;
    Node *newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *p = *head;
    while (p->next) p = p->next;
    p->next = newNode;
}

void addFirst(Node **head, int val) {
    if (exists(*head, val)) return;
    Node *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void addAfter(Node *head, int u, int v) {
    if (!exists(head, u) || exists(head, v)) return;
    for (Node *p = head; p; p = p->next) {
        if (p->val == u) {
            Node *newNode = createNode(v);
            newNode->next = p->next;
            p->next = newNode;
            return;
        }
    }
}

void addBefore(Node **head, int u, int v) {
    if (!exists(*head, u) || exists(*head, v)) return;
    Node *newNode = createNode(v);
    if ((*head)->val == u) { // insert before first
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *p = *head;
    while (p->next && p->next->val != u) p = p->next;
    if (p->next) {
        newNode->next = p->next;
        p->next = newNode;
    }
}

void removeKey(Node **head, int k) {
    if (!exists(*head, k)) return;
    Node *p = *head;
    if (p->val == k) {
        *head = p->next;
        free(p);
        return;
    }
    while (p->next && p->next->val != k) p = p->next;
    if (p->next) {
        Node *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

void reverseList(Node **head) {
    Node *prev = NULL, *cur = *head, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
void printList(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d", p->val);
        if (p->next) printf(" ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        addLast(&head, x);
    }
    char cmd[20];
    while (1) {
        scanf("%s", cmd);
        if (cmd[0] == '#') break;
        if (strcmp(cmd, "addlast") == 0) {
            int x; scanf("%d", &x);
            addLast(&head, x);
        } else if (strcmp(cmd, "addfirst") == 0) {
            int x; scanf("%d", &x);
            addFirst(&head, x);
        } else if (strcmp(cmd, "addafter") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addAfter(head, u, v);
        } else if (strcmp(cmd, "addbefore") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addBefore(&head, u, v);
        } else if (strcmp(cmd, "remove") == 0) {
            int k; scanf("%d", &k);
            removeKey(&head, k);
        } else if (strcmp(cmd, "reverse") == 0) {
            reverseList(&head);
        }
    }
    printList(head);
    return 0;
}
