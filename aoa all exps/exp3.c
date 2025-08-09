#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void exchange(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            exchange(&arr[i], &arr[j]);
        }
    }
    exchange(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

bool is_integer(const char* s) {
    if (s == NULL || *s == '\0' || isspace((unsigned char)*s))
        return false;
    char* p;
    strtol(s, &p, 10);
    return (*p == '\0' || *p == '\n');
}

int main() {
    int arr_size;
    printf("Enter the number of elements in the array: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    if (!is_integer(input)) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }
    arr_size = atoi(input);
    if (arr_size <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    int* arr = (int*)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        fgets(input, sizeof(input), stdin);
        if (!is_integer(input)) {
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

    printf("Given array is:\n");
    print_array(arr, arr_size);

    quick_sort(arr, 0, arr_size - 1);

    printf("\nSorted array is:\n");
    print_array(arr, arr_size);

    free(arr);
    return 0;
}
