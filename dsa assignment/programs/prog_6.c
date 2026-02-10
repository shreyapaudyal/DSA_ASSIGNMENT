#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) 
        largest = left;
    if (right < n && arr[right] > arr[largest]) 
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest]) 
        smallest = left;
    if (right < n && arr[right] < arr[smallest]) 
        smallest = right;
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void buildMinHeap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void printArray(int arr[], int n, const char *msg) {
    int i;
    printf("%s: ", msg);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printHeapTree(int arr[], int n) {
    int i, count = 0, elementsInLevel = 1;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count++;
        if (count == elementsInLevel) {
            printf("\n");
            elementsInLevel *= 2;
            count = 0;
        }
    }
    if (count != 0) printf("\n");
}

int main() {
    int data[] = {45, 12, 78, 34, 23, 67, 89, 5, 19, 56};
    int n = sizeof(data) / sizeof(data[0]);
    int i;
    int maxHeap[10], minHeap[10];
    
    for (i = 0; i < n; i++) {
        maxHeap[i] = data[i];
        minHeap[i] = data[i];
    }
    
    printArray(data, n, "Original");
    
    buildMaxHeap(maxHeap, n);
    printf("\n");
    printArray(maxHeap, n, "Max Heap");
    printHeapTree(maxHeap, n);
    
    buildMinHeap(minHeap, n);
    printf("\n");
    printArray(minHeap, n, "Min Heap");
    printHeapTree(minHeap, n);
    
    return 0;
}