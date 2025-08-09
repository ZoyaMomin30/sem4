#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // Include limits.h for INT_MAX and INT_MIN

// Function to find the minimum and maximum elements in an array
void find_min_max(int arr[], int n, int* min, int* max) {
    *min = INT_MAX; // Initialize min to the maximum possible integer value
    *max = INT_MIN; // Initialize max to the minimum possible integer value

    for (int i = 0; i < n; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}

// Function to check if a string represents a valid integer
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

    int min, max;
    find_min_max(arr, arr_size, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    free(arr);
    return 0;
}
