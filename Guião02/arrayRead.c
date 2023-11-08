// Read the number of elements, allocate the array and read its elements
// Condition: number of elements > 0
// Pre-Condition: size_p != NULL
// Return NULL if memory allocation fails
// Set *size_p to ZERO if memory allocation fails

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

double* ReadArray(size_t* size_p) {
    double* a = NULL;
    size_t n = 0;
    
    // Read the number of elements
    printf("Number of elements: ");
    if (scanf("%zu", &n) != 1 || n <= 0) {
        // Invalid input, set size_p to 0 and return NULL
        *size_p = 0;
        return NULL;
    }

    // Allocate memory for the array
    a = (double*)malloc(n * sizeof(double));

    if (a == NULL) {
        // Memory allocation failed, set size_p to 0
        *size_p = 0;
        return NULL;
    }

    // Read the elements into the array
    for (size_t i = 0; i < n; i++) {
        printf("Element %zu: ", i);
        if (scanf("%lf", &a[i]) != 1) {
            // Error reading an element, free the allocated memory and return NULL
            free(a);
            *size_p = 0;
            return NULL;
        }
    }

    *size_p = n;
    return a;
}

int main() {
    size_t size;
    double* arr = ReadArray(&size);

    if (arr != NULL) {
        // Successfully allocated and read the array
        printf("Array contents:\n");
        for (size_t i = 0; i < size; i++) {
            printf("%.2lf ", arr[i]);
        }
        printf("\n");

        // Don't forget to free the allocated memory when done
        free(arr);
    } else {
        printf("Memory allocation or input error.\n");
    }

    return 0;
}
