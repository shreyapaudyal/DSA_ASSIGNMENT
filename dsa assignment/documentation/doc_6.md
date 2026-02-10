# Min Heap and Max Heap from Unsorted Array

## Data Structure Definition

Array-based heap with implicit tree structure:
- Parent of index i: `(i-1)/2`
- Left child of i: `2*i + 1`
- Right child of i: `2*i + 2`

**Max Heap:** Parent ≥ children  
**Min Heap:** Parent ≤ children

## Functions Implemented

**`swap(int *a, int *b)`** - Swaps two integers.

**`maxHeapify(int arr[], int n, int i)`** - Ensures max heap property at index i. Finds largest among node and children, swaps if needed, recurses.

**`minHeapify(int arr[], int n, int i)`** - Ensures min heap property at index i. Finds smallest among node and children, swaps if needed, recurses.

**`buildMaxHeap(int arr[], int n)`** - Converts array to max heap. Calls maxHeapify from last non-leaf `(n/2-1)` to root.

**`buildMinHeap(int arr[], int n)`** - Converts array to min heap. Calls minHeapify from last non-leaf to root.

**`printArray(int arr[], int n, char *msg)`** - Prints array with label.

**`printHeapTree(int arr[], int n)`** - Displays heap in level-order tree format.

## Main Method Organization

1. Initialize unsorted array: {45, 12, 78, 34, 23, 67, 89, 5, 19, 56}
2. Create two copies
3. Build and display max heap
4. Build and display min heap

## Sample Output
```
Original: 45 12 78 34 23 67 89 5 19 56 

Max Heap: 89 56 78 34 23 67 45 5 19 12 
89 
56 78 
34 23 67 45 
5 19 12 

Min Heap: 5 12 67 19 23 78 89 45 34 56 
5 
12 67 
19 23 78 89 
45 34 56 
```

**Time Complexity:** O(n) for building heap, O(log n) for heapify  
**Space Complexity:** O(1) - in-place operation