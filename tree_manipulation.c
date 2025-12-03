#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Định nghĩa cấu trúc nút cây theo dạng: Con trái - Anh em phải
typedef struct Node {
    int id;
    struct Node* leftChild;   // Trỏ đến con đầu tiên
    struct Node* rightSibling; // Trỏ đến anh em kế tiếp
} Node;

// Nút gốc của cây
Node* root = NULL;

// Hàm tạo nút mới
Node* makeNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightSibling = NULL;
    return p;
}

// Hàm tìm kiếm một nút có id cụ thể trong cây
// Trả về con trỏ tới nút đó, hoặc NULL nếu không tìm thấy
Node* find(Node* r, int id) {
    if (r == NULL) return NULL;
    if (r->id == id) return r;

    // Tìm trong danh sách con của r
    Node* p = r->leftChild;
    while (p != NULL) {
        Node* q = find(p, id);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

// Hàm xử lý lệnh MakeRoot
void makeRoot(int u) {
    if (root == NULL) {
        root = makeNode(u);
    }
}

// Hàm xử lý lệnh Insert u v (chèn u vào cuối danh sách con của v)
void insert(int u, int v) {
    // 1. Kiểm tra xem u đã tồn tại chưa, nếu có rồi thì không làm gì
    if (find(root, u) != NULL) return;

    // 2. Kiểm tra xem v có tồn tại không, nếu không thì không làm gì
    Node* parent = find(root, v);
    if (parent == NULL) return;

    // 3. Tạo nút mới u
    Node* newNode = makeNode(u);

    // 4. Chèn u vào cuối danh sách con của v
    if (parent->leftChild == NULL) {
        // Nếu v chưa có con, u là con đầu tiên
        parent->leftChild = newNode;
    } else {
        // Nếu v đã có con, duyệt đến con cuối cùng
        Node* p = parent->leftChild;
        while (p->rightSibling != NULL) {
            p = p->rightSibling;
        }
        p->rightSibling = newNode;
    }
}

// Duyệt PreOrder: Gốc -> Các con
void preOrder(Node* r) {
    if (r == NULL) return;

    printf("%d ", r->id); // Thăm gốc

    Node* p = r->leftChild;
    while (p != NULL) {
        preOrder(p); // Thăm các con
        p = p->rightSibling;
    }
}
// Duyệt InOrder: Con đầu -> Gốc -> Các con còn lại
void inOrder(Node* r) {
    if (r == NULL) return;

    Node* p = r->leftChild;

    // Thăm cây con thứ nhất (nếu có)
    if (p != NULL) {
        inOrder(p);
        p = p->rightSibling; // Chuyển sang con thứ 2 để chuẩn bị cho vòng lặp sau
    }

    printf("%d ", r->id); // Thăm gốc

    // Thăm các cây con còn lại
    while (p != NULL) {
        inOrder(p);
        p = p->rightSibling;
    }
}

// Duyệt PostOrder: Các con -> Gốc
void postOrder(Node* r) {
    if (r == NULL) return;
    Node* p = r->leftChild;
    while (p != NULL) {
        postOrder(p); // Thăm các con trước
        p = p->rightSibling;
    }

    printf("%d ", r->id); // Thăm gốc sau cùng
}

// Hàm giải phóng bộ nhớ (tùy chọn, tốt cho thực hành)
void freeTree(Node* r) {
    if (r == NULL) return;
    Node* p = r->leftChild;
    while (p != NULL) {
        Node* next = p->rightSibling;
        freeTree(p);
        p = next;
    }
    free(r);
}

int main() {
    char cmd[20];
    int u, v;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "*") == 0) {
            break;
        } else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            makeRoot(u);
        } else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insert(u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }
    freeTree(root);
    return 0;
}