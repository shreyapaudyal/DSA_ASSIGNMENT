#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void insert(struct Node **head, int data) {
    struct Node *node = createNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
        node->prev = temp;
    }
}

void insertAfter(struct Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    struct Node *node = createNode(data);
    node->next = prevNode->next;
    prevNode->next = node;
    node->prev = prevNode;
    
    if (node->next != NULL)
        node->next->prev = node;
    
    printf("Inserted %d after %d\n", data, prevNode->data);
}

void deleteNode(struct Node **head, struct Node *delNode) {
    if (*head == NULL || delNode == NULL) return;
    
    if (*head == delNode)
        *head = delNode->next;
    
    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;
    
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;
    
    printf("Deleted %d\n", delNode->data);
    free(delNode);
}

void displayForward(struct Node *head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayBackward(struct Node *head) {
    if (head == NULL) return;
    while (head->next != NULL) head = head->next;
    
    printf("Backward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    
    printf("Initial list:\n");
    displayForward(head);
    displayBackward(head);
    
    printf("\n");
    insertAfter(head->next, 25);  // Insert 25 after 20
    displayForward(head);
    
    printf("\n");
    deleteNode(&head, head->next->next->next);  // Delete 30
    displayForward(head);
    displayBackward(head);
    
    return 0;
}