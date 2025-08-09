#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input the number of elements from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Check if n is negative
    if (n < 0) {
        printf("Number of elements cannot be negative.\n");
        return 1; // Exit the program with error code 1
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation failed
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with error code 1
    }

    // Input the elements of the array from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Check if array elements are negative
        if (arr[i] < 0) {
            printf("Array elements cannot be negative.\n");
            free(arr);
            return 1; // Exit the program with error code 1
        }
    }

    // Sort the array using selection sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
