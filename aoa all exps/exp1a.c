#include <stdio.h> 
#include <stdlib.h>

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        if(min_idx != i) 
            swap(&arr[min_idx], &arr[i]); 
    } 
} 

void printArray(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() { 
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Check if n is negative
    if (n < 0) {
        printf("Number of elements cannot be negative.\n");
        return 1; // Exit the program with error code 1
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
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
    
    selectionSort(arr, n); 
    
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    
    free(arr);
    return 0; 
}
