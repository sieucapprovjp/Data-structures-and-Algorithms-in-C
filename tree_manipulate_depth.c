#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_ID 100005

typedef struct Node {
    int id;
    int depth;
    struct Node *firstChild;  // Đổi tên từ firstSibling thành firstChild cho đúng bản chất
    struct Node *nextSibling;
} Node;

Node* nodes[Max_ID];
Node* root = NULL;

Node *makeNode(int id, int depth) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->depth = depth;
    p->firstChild = NULL;  // Sửa tên
    p->nextSibling = NULL;
    return p;
}

void insert(int u, int v) {
    if (nodes[v] != NULL) {
        Node* parent = nodes[v];
        // Tạo node con u, độ sâu = độ sâu cha + 1
        Node* child = makeNode(u, parent->depth + 1);
        nodes[u] = child; // Cập nhật mảng lookup

        if (parent->firstChild == NULL) {
            parent->firstChild = child;
        } else {
            Node *temp = parent->firstChild;
            // FIX LỖI 1: Duyệt đến node anh em cuối cùng
            while (temp->nextSibling != NULL) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
    }
}

int computeHeight(Node *u) {
    if (u == NULL) return 0;
    int maxH = 0;
    Node *child = u->firstChild;//Sửa tên
    while (child != NULL) {
        int h = computeHeight(child);
        if (h > maxH) maxH = h;
        child = child->nextSibling;
    }
    return maxH + 1;
}

int main() {
    // FIX LỖI 2: Dùng dấu = thay vì ==
    for (int i = 0; i < Max_ID; i++) {
        nodes[i] = NULL;
    }

    char cmd[20];
    while (1) {
        scanf("%s", cmd); // Bỏ dấu & trước cmd vì cmd đã là địa chỉ mảng
        if (strcmp(cmd, "*") == 0) {
            break; // Thoát vòng lặp sạch sẽ hơn
        } else if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u, 1);
            nodes[u] = root;
        } else if (strcmp(cmd, "Insert") == 0) {
            int u, v;
            scanf("%d %d", &u, &v); // Chèn u vào v
            insert(u, v);
        } else if (strcmp(cmd, "Height") == 0) {
            int u;
            scanf("%d", &u);
            if (nodes[u] != NULL) {
                printf("%d\n", computeHeight(nodes[u]));
            }
        } else if (strcmp(cmd, "Depth") == 0) {
            int u;
            scanf("%d", &u);
            if (nodes[u] != NULL) {
                printf("%d\n", nodes[u]->depth);
            }
        }
    }
    return 0;
}