#include <stdio.h>

void heapifyMin(int arr[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        heapifyMin(arr, n, smallest);
    }
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapifyMax(arr, n, largest);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;
int i;
    for ( i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    printf("Min Heap: ");
    for ( i = 0; i < n; i++) printf("%d ", arr[i]);

    for ( i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    printf("\nMax Heap: ");
    for ( i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}


