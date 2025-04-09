#include <stdio.h>
#include <stdlib.h>

// Define a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// In-order traversal (sorted order)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Free BST memory
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int arr[] = {50, 20, 70, 10, 30, 60, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = NULL;

    // Build the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Display sorted order
    printf("Sorted List: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}