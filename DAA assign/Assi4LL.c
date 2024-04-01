#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    current->next = head; 
    return head;
}

int josephusCircularLinkedList(struct Node** head, int k) {
    if (*head == NULL) {
        return -1;  
    }
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != *head) {
        prev = current;
        current = current->next;
    }
    while (*head != current) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free(current);
        current = prev->next;
    }

    int survivor = current->data;
    free(current);

    *head = NULL; 
    return survivor;
}

int main() {
    int n, k;

    printf("Enter the total number of people (n): ");
    scanf("%d", &n);

    printf("Enter the counting interval (k): ");
    scanf("%d", &k);

    struct Node* head = createCircularLinkedList(n);

    int survivor = josephusCircularLinkedList(&head, k);
    printf("The survivor in the Josephus problem is at position %d.\n", survivor);

    return 0;
}
