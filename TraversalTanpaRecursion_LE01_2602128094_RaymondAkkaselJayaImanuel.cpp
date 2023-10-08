#include <stdio.h>
#include <stdlib.h>

/*
	NIM : 2602128094
	Nama : Raymond Akkasel Jaya Imanuel
*/

// template node nya
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Pre-order Traversal tanpa recursion
void preOrderWithoutRecursion(Node *root) {
    if (root == NULL) return;

    Node *stack[100];  // misal jumlah node maksimal itu 100, tapi yg diperluin di soal cuma 13 node
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        Node *node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
    printf("\n");
}

// In-order Traversal tanpa recursion
void inOrderWithoutRecursion(Node *root) {
    if (root == NULL) return;

    Node *stack[100];
    int top = -1;
    Node *current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

// Post-Order Traversal tanpa recursion
void postOrderWithoutRecursion(Node *root) {
    if (root == NULL) return;

    Node *stack1[100];
    Node *stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        Node *node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) stack1[++top1] = node->left;
        if (node->right != NULL) stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

// Queue
typedef struct Queue {
    Node *data[100];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, Node *node) {
    q->data[++q->rear] = node;
}

Node* dequeue(Queue *q) {
    return q->data[q->front++];
}

// Level-order Traversal tanpa recursion
void levelOrderWithoutRecursion(Node *root) {
    if (root == NULL) return;

    Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    while (q.front <= q.rear) {
        Node *node = dequeue(&q);
        printf("%d ", node->data);

        if (node->left != NULL) enqueue(&q, node->left);
        if (node->right != NULL) enqueue(&q, node->right);
    }
    printf("\n");
}


int main() {
    
    // Anggap 1 = A
    // 2 = B
    // 3 = C
    // 4 = D
    // 5 = E
    // 6 = F
    // 7 = G
    // 8 = H
    // 9 = I
    // 10 = J
    // 11 = K
    // 12 = L
    // 13 = M
    
    // initialize tiap node
    Node *root = (Node *) malloc(sizeof(Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    Node *left1 = (Node *) malloc(sizeof(Node));
    left1->data = 2;
    left1->left = NULL;
    left1->right = NULL;

    Node *right1 = (Node *) malloc(sizeof(Node));
    right1->data = 3;
    right1->left = NULL;
    right1->right = NULL;

    Node *left2 = (Node *) malloc(sizeof(Node));
    left2->data = 4;
    left2->left = NULL;
    left2->right = NULL;

    Node *right2 = (Node *) malloc(sizeof(Node));
    right2->data = 5;
    right2->left = NULL;
    right2->right = NULL;
    
    Node *left3 = (Node *) malloc(sizeof(Node));
    left3->data = 6;
    left3->left = NULL;
    left3->right = NULL;

    Node *right3 = (Node *) malloc(sizeof(Node));
    right3->data = 7;
    right3->left = NULL;
    right3->right = NULL;
    
    Node *left4 = (Node *) malloc(sizeof(Node));
    left4->data = 8;
    left4->left = NULL;
    left4->right = NULL;

    Node *right4 = (Node *) malloc(sizeof(Node));
    right4->data = 9;
    right4->left = NULL;
    right4->right = NULL;
    
    Node *left5 = (Node *) malloc(sizeof(Node));
    left5->data = 0;
    left5->left = NULL;
    left5->right = NULL;

    Node *right5 = (Node *) malloc(sizeof(Node));
    right5->data = 0;
    right5->left = NULL;
    right5->right = NULL;
    
    Node *left6 = (Node *) malloc(sizeof(Node));
    left6->data = 10;
    left6->left = NULL;
    left6->right = NULL;

    Node *right6 = (Node *) malloc(sizeof(Node));
    right6->data = 11;
    right6->left = NULL;
    right6->right = NULL;
    
    Node *left7 = (Node *) malloc(sizeof(Node));
    left7->data = 12;
    left7->left = NULL;
    left7->right = NULL;

    Node *right7 = (Node *) malloc(sizeof(Node));
    right7->data = 13;
    right7->left = NULL;
    right7->right = NULL;
    
    root->left = left1;
    root->right = right1;

    left1->left = left2;
    left1->right = right2;

    right1->left = left3;
    right1->right = right3;

    left2->left = left4;
    left2->right = right4;

    right2->left = left5;
    right2->right = right5;
    
    left3->left = left6;
    left3->right = right6;

    right3->left = left7;
    right3->right = right7;
    
    // initialize child node dari "E" menjadi NULL supaya ga error.
    left5->left = NULL;
    left5->right = NULL;
    right5->left = NULL;
    right5->right = NULL;
    
    printf("Pre-order traversal: ");
    preOrderWithoutRecursion(root);

    printf("In-order traversal: ");
    inOrderWithoutRecursion(root);

    printf("Post-order traversal: ");
    postOrderWithoutRecursion(root);

    printf("Level-order traversal: ");
    levelOrderWithoutRecursion(root);
    
    // free memory nyaa
    free(root);
	free(left1);
	free(right1);
	free(left2);
	free(right2);
	free(left3);
	free(right3);
	free(left4);
	free(right4);
	free(left5);  
	free(right5); 
	free(left6);
	free(right6);
	free(left7);
	free(right7);

    return 0;
}
