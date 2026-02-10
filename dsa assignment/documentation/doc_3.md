# Reverse Traversal of Linked List

## Data Structure Definition
```c
struct Node {
    int data;           // Integer value
    struct Node *next;  // Pointer to next node
};
```

Singly linked list with data and next pointer. Head pointer tracks the first node.

## Functions Implemented

**`createNode(int data)`** - Allocates and initializes a new node with given data.

**`insert(struct Node **head, int data)`** - Appends new node at the end of list.

**`reverseTraversal(struct Node *head)`** - Recursively prints list in reverse. Goes to end first, then prints during recursion unwinding.

**`display(struct Node *head)`** - Iteratively prints list in forward order.

## Main Method Organization

1. Initialize empty list
2. Insert nodes: 10, 20, 30, 40, 50
3. Display forward
4. Display reverse using recursion

## Sample Output
```
Forward: 10 20 30 40 50 
Reverse: 50 40 30 20 10 
```