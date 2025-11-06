#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int row;
    int columns;
    int step;
    struct Node* next;
}Node;

int n,m;
int A[1000][1000];
int sr,sc;
int visited[1000][1000];
Node *first;
Node *last;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

Node *makeNode(int r,int c,int step) {
    Node *p= (Node*)malloc(sizeof(Node));
    p -> row = r;
    p-> columns = c;
    p -> step = step;
    p -> next = NULL;
    return p;
}
int isEmpty() {
    return first == NULL && last == NULL;
}
void push(Node *p) {
    if (isEmpty()) {
        first =p;
        last=p;
        return;
    }
    last -> next = p;
    last = p;
}
Node* pop() {
    if (isEmpty()) {
        return NULL;
    }
    Node *temp = first;
    first = first -> next;
    if (first == NULL) {
        last = NULL;
        return temp;
    }
}
void input() {
    scanf("%d %d %d %d",&n,&m,&sr,&sc);
    for (int i=1;i <= n;i++) {
        for (int j =1; j <= m;j++) {
            scanf("%d",&A[i][j]);
        }
    }
}
int targetStates(Node *s) {
    return (s-> row<1 || s -> row>n || s -> columns <1 || s -> columns >m);
}
void init() {
    first = NULL;
    last = NULL;
    for (int i=0;i<1000;i++) {
        for (int j =0;j<1000;j++) {
            visited[i][j] = 0;
        }
    }
    Node* startState = makeNode(sr,sc,0);
    push(startState);
    visited[sr][sc] =1;
}
int solve() {
    init();
    while (!isEmpty()) {
        Node* s= pop();
        for (int k = 0;k<4;k++) {
            int nr = s -> row +dr[k];
            int nc = s -> columns + dc[k];
            if (visited[nr][nc]== 0 && A[nr][nc]==0) {
                Node *ns = makeNode(nr,nc,s->step+1);
                push(ns);
                visited[nr][nc] =1;
                if (targetStates(ns)) {
                    return ns -> step;
                }
            }
        }
    }
    return -1;
}
int main() {
    input();
    int res = solve();
    printf("%d",res);
    return 0;
}