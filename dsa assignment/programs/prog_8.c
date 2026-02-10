#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Bubble Sort
void bubbleSort(int data[], int size, int *comp, int *swap) {
    *comp = 0;
    *swap = 0;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            (*comp)++;
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                (*swap)++;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int data[], int size, int *comp, int *swap) {
    *comp = 0;
    *swap = 0;
    int minPos, temp;
    for (int i = 0; i < size - 1; i++) {
        minPos = i;
        for (int j = i + 1; j < size; j++) {
            (*comp)++;
            if (data[j] < data[minPos])
                minPos = j;
        }
        if (i != minPos) {
            temp = data[i];
            data[i] = data[minPos];
            data[minPos] = temp;
            (*swap)++;
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int data[], int size, int *comp, int *swap) {
    *comp = 0;
    *swap = 0;
    int current, pos;
    for (int i = 1; i < size; i++) {
        current = data[i];
        pos = i - 1;
        while (pos >= 0 && data[pos] > current) {
            (*comp)++;
            data[pos + 1] = data[pos];
            (*swap)++;
            pos--;
        }
        if (pos >= 0) (*comp)++;
        data[pos + 1] = current;
    }
}

// Merge function for Merge Sort
void mergeArrays(int data[], int start, int middle, int end, int *comp, int *swap) {
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    
    int *leftArr = (int*)malloc(leftSize * sizeof(int));
    int *rightArr = (int*)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = data[start + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = data[middle + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        (*comp)++;
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        (*swap)++;
        k++;
    }

    while (i < leftSize) {
        data[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        data[k] = rightArr[j];
        j++;
        k++;
    }
    
    free(leftArr);
    free(rightArr);
}

// Merge Sort function
void performMergeSort(int data[], int start, int end, int *comp, int *swap) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        performMergeSort(data, start, middle, comp, swap);
        performMergeSort(data, middle + 1, end, comp, swap);
        mergeArrays(data, start, middle, end, comp, swap);
    }
}

// Function to print array
void printArray(int data[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int main() {
    int num;
    printf("Enter number of random integers to generate: ");
    scanf("%d", &num);

    int *numbers = (int*)malloc(num * sizeof(int));
    int *sortedArr = (int*)malloc(num * sizeof(int));

    srand(time(0));
    for (int i = 0; i < num; i++)
        numbers[i] = (rand() % 1000) + 1;

    printf("\nArray before sorting:\n");
    printArray(numbers, num);

    printf("\nSelect a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    
    int option;
    scanf("%d", &option);

    for (int i = 0; i < num; i++)
        sortedArr[i] = numbers[i];

    int compCount = 0, swapCount = 0;

    switch (option) {
        case 1:
            bubbleSort(sortedArr, num, &compCount, &swapCount);
            printf("\nArray after Bubble Sort:\n");
            break;
        case 2:
            selectionSort(sortedArr, num, &compCount, &swapCount);
            printf("\nArray after Selection Sort:\n");
            break;
        case 3:
            insertionSort(sortedArr, num, &compCount, &swapCount);
            printf("\nArray after Insertion Sort:\n");
            break;
        case 4:
            performMergeSort(sortedArr, 0, num - 1, &compCount, &swapCount);
            printf("\nArray after Merge Sort:\n");
            break;
        default:
            printf("Invalid option!\n");
            free(numbers);
            free(sortedArr);
            return 0;
    }

    printArray(sortedArr, num);
    printf("\nComparisons made: %d\n", compCount);
    printf("Swaps/Moves made: %d\n", swapCount);

    free(numbers);
    free(sortedArr);

    return 0;
}