#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp = 0, swap = 0;

void bubbleSort(int a[], int n) {
	int i,j,t;
    for ( i = 0; i < n-1; i++)
        for ( j = 0; j < n-i-1; j++) {
            comp++;
            if (a[j] > a[j+1]) {
                 t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                swap++;
            }
        }
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int i;
    int a[n];
    srand(time(0));

    for ( i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    printf("Before Sorting:\n");
    for ( i = 0; i < n; i++) printf("%d ", a[i]);

    bubbleSort(a, n);

    printf("\nAfter Sorting:\n");
    for ( i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nComparisons: %d", comp);
    printf("\nSwaps: %d", swap);

    return 0;
}
