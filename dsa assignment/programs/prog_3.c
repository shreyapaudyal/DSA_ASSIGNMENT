#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
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
    }
}

void reverseTraversal(struct Node *head) {
    if (head == NULL) return;
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    
    printf("Forward: ");
    display(head);
    
    printf("Reverse: ");
    reverseTraversal(head);
    printf("\n");
    
    return 0;
}