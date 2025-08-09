#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

bool isInteger(const char *s) {
    if (s == NULL || *s == '\0' || isspace((unsigned char)*s))
        return false;
    char *p;
    strtol(s, &p, 10);
    return (*p == '\0' || *p == '\n'); // Corrected to allow for negative numbers and handle newline character
}

int main() {
    int arr_size;
    printf("Enter the number of elements in the array: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    if (!isInteger(input)) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }
    arr_size = atoi(input);
    if (arr_size <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        fgets(input, sizeof(input), stdin);
        if (!isInteger(input)) {
            printf("Invalid input. Please enter an integer.\n");
            free(arr);
            return 1;
        }
        arr[i] = atoi(input);
        if (arr[i] < 0) {
            printf("Array elements cannot be negative.\n");
            free(arr);
            return 1;
        }
    }

    printf("Given array is\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is\n");
    printArray(arr, arr_size);

    free(arr);
    return 0;
}
