# Doubly Linked List - Insert After and Delete

## Data Structure Definition
```c
struct Node {
    int data;           // Integer value
    struct Node *prev;  // Pointer to previous node
    struct Node *next;  // Pointer to next node
};
```

Doubly linked list enables bidirectional traversal with prev and next pointers.

## Functions Implemented

**`createNode(int data)`** - Creates new node with NULL prev/next pointers.

**`insert(struct Node **head, int data)`** - Appends node at end, maintaining bidirectional links.

**`insertAfter(struct Node *prevNode, int data)`** - Inserts new node after specified node. Updates 4 pointers to maintain integrity.

**`deleteNode(struct Node **head, struct Node *delNode)`** - Removes node by adjusting adjacent pointers. Updates head if needed.

**`displayForward(struct Node *head)`** - Prints list head to tail.

**`displayBackward(struct Node *head)`** - Traverses to tail, then prints tail to head.

## Main Method Organization

1. Create list: 10, 20, 30, 40
2. Display both directions
3. Insert 25 after node with 20
4. Delete node with 30
5. Display final state both directions

## Sample Output
```
Initial list:
Forward: 10 20 30 40 
Backward: 40 30 20 10 

Inserted 25 after 20
Forward: 10 20 25 30 40 

Deleted 30
Forward: 10 20 25 40 
Backward: 40 25 20 10 
```