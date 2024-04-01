#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int item) {
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct TreeNode *insertNode(struct TreeNode *root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

void printBST(struct TreeNode *root) {
    if (root != NULL) {
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }
}

struct TreeNode *arrayToBST(int array[], int low, int high) {
    struct TreeNode *root = NULL;
    for (int i = low; i <= high; i++) {
        root = insertNode(root, array[i]);
        printf("Binary Tree after insert: ");
        printBST(root);
        printf("\n");
    }
    return root;
}

struct TreeNode *sortedArrayToBST(int array[], int size) {
    return arrayToBST(array, 0, size - 1);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
            printf("Array after swap: ");
            printArray(array, high + 1);
        }
    }
    swap(&array[i + 1], &array[high]);
    printf("Array after partition: ");
    printArray(array, high + 1);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    struct TreeNode *bstRoot = sortedArrayToBST(data, n);

    printf("In-order Traversal of the Constructed Binary Search Tree:\n");
    inOrderTraversal(bstRoot);

    return 0;
}
