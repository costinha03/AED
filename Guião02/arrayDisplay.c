// Display the contents of array a with n elements
// Pre-Conditions: a != NULL and n > 0
// Example of produced output: Array = [ 1.00, 2.00, 3.00 ]

#include<stdio.h>


void DisplayArray(double* a, size_t n) {
    if (a != NULL && n > 0){
        printf("Array = [ ");
        for (size_t i = 0; i < n; i++) {
            printf("%.2f", a[i]);
            if (i < n - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");}  
    else {  printf("Valores de entrada inválidos\n");} 

}

int main(void){
    double a[] = {1.0, 2.0, 3.0};
    DisplayArray(a, 3);
    return 0;
}
