
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node_from_input() {
    int value;
    printf("Nhập số nguyên cho phần tử: ");
    scanf("%d", &value);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* create_node_with_value(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

typedef struct queue_node {
    node *tree_node;
    struct queue_node *next;
} queue_node;

typedef struct queue {
    queue_node *front;
    queue_node *rear;
} queue;

int is_empty(queue* q) {
    return q->front == NULL;
}

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue* q, node* value) {
    queue_node* newnode = (queue_node*)malloc(sizeof(queue_node));
    newnode->tree_node = value;
    newnode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

node* dequeue(queue* q) {
    if (is_empty(q)) return NULL;
    queue_node* temp = q->front;
    node* second = temp->tree_node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return second;
}

void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void add_element(node* root, int value) {
    if (root == NULL) return;

    queue* q = create_queue();
    enqueue(q, root);

    while (!is_empty(q)) {
        node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = create_node_with_value(value);
            return;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = create_node_with_value(value);
            return;
        } else {
            enqueue(q, current->right);
        }
    }
}
int find_max(node* root) {
    if (root == NULL) return -999999; // giá trị cực nhỏ

    int max_left = find_max(root->left);
    int max_right = find_max(root->right);
    int max_child;

    if (max_left > max_right)
        max_child = max_left;
    else
        max_child = max_right;

    if (root->data > max_child)
        return root->data;
    else
        return max_child;
}

int find_level(node* root, int target) {
    if (root == NULL) return -1;

    queue* q = create_queue();  // dùng queue đã tạo từ trước
    enqueue(q, root);

    int level = 0;

    while (!is_empty(q)) {
        int size = 0;
        queue_node* temp = q->front;
        while (temp) {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; ++i) {
            node* current = dequeue(q);
            if (current->data == target)
                return level;

            if (current->left) enqueue(q, current->left);
            if (current->right) enqueue(q, current->right);
        }

        level++;
    }

    return -1; // không tìm thấy
}

int main(void) {
    node* root = create_node_from_input();
    root->left = create_node_from_input();
    root->right = create_node_from_input();
    root->left->left = create_node_from_input();

    printf("Duyệt cây theo hậu thứ tự: ");
    postorder(root);

    printf("Giá trị lớn nhất trong cây là: %d\\n", find_max(root));
    int val;
    printf("Nhập giá trị cần tìm tầng: ");
    scanf("%d", &val);
    int lv = find_level(root, val);
    if (lv != -1)
        printf("Giá trị %d nằm ở tầng %d\n", val, lv);
    else
        printf("Không tìm thấy giá trị %d trong cây\n", val);




    return 0;
}
