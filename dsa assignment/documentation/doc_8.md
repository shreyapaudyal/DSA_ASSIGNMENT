# Sorting Algorithm Comparison Program - Documentation

## Data Structures

### Arrays
- **`numbers[]`**: Stores original randomly generated integers (dynamically allocated)
- **`sortedArr[]`**: Copy of numbers array for sorting (dynamically allocated)
- **`leftArr[]`, `rightArr[]`**: Temporary arrays for merge operation in Merge Sort

### Variables
- **`num`**: Number of elements to generate
- **`compCount`**: Total comparisons counter
- **`swapCount`**: Total swaps/moves counter
- **`option`**: User's algorithm choice (1-4)

---

## Functions

### 1. `bubbleSort(int data[], int size, int *comp, int *swap)`
Compares adjacent elements and swaps if out of order. Largest elements bubble to the end through nested loops.

### 2. `selectionSort(int data[], int size, int *comp, int *swap)`
Finds minimum element from unsorted portion and swaps with first unsorted position.

### 3. `insertionSort(int data[], int size, int *comp, int *swap)`
Builds sorted array by inserting each element into correct position, shifting others as needed.

### 4. `performMergeSort(int data[], int start, int end, int *comp, int *swap)`
Recursively divides array into halves and merges them back in sorted order.

### 5. `mergeArrays(int data[], int start, int middle, int end, int *comp, int *swap)`
Helper function that merges two sorted subarrays into one sorted array.

### 6. `printArray(int data[], int size)`
Displays array elements separated by spaces.

---

## Main Function Flow

1. **Input**: Get number of elements from user
2. **Allocation**: Allocate memory for arrays using malloc
3. **Generation**: Generate random numbers [1-1000] using rand()
4. **Display**: Print original array
5. **Selection**: Show menu and get user's sorting choice
6. **Copy**: Copy original array to sortedArr
7. **Sort**: Execute chosen algorithm with switch-case
8. **Output**: Display sorted array, comparisons, and swaps
9. **Cleanup**: Free allocated memory

---

## Sample Output

```
Enter number of random integers to generate: 10

Array before sorting:
742 231 456 892 123 667 334 901 555 178

Select a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Array after Bubble Sort:
123 178 231 334 456 555 667 742 892 901

Comparisons made: 45
Swaps/Moves made: 19
```

```
Enter number of random integers to generate: 8

Array before sorting:
523 891 234 675 123 456 789 342

Select a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 4

Array after Merge Sort:
123 234 342 456 523 675 789 891

Comparisons made: 13
Swaps/Moves made: 17
```