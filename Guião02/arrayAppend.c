#include <stdio.h>
#include <stdlib.h>

double* Append(double* array_1, size_t size_1, double* array_2, size_t size_2) {
    // Check pre-conditions
    if (array_1 == NULL || array_2 == NULL || size_1 <= 0 || size_2 <= 0) {
        printf("Error! Invalid input!\n");
        return NULL;
    }

    // Allocate memory for the new array
    double* result = (double*)malloc((size_1 + size_2) * sizeof(double));

    // Check if memory allocation fails
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy elements from array_1 to result
    for (size_t i = 0; i < size_1; i++) {
        result[i] = array_1[i];
    }

    // Copy elements from array_2 to result
    for (size_t i = 0; i < size_2; i++) {
        result[size_1 + i] = array_2[i];
    }

    return result;
}

int main(void) {
    double array_1[] = {1.0, 2.0, 3.0};
    double array_2[] = {4.0, 5.0, 6.0};
    size_t size_1 = 3;
    size_t size_2 = 3;

    double* result = Append(array_1, size_1, array_2, size_2);

    if (result == NULL) {
        return 1; 
    }

    for (size_t i = 0; i < size_1 + size_2; i++) {
        printf("%.1f ", result[i]);
    }
    
    // Free the allocated memory
    free(result);

    return 0;
}
