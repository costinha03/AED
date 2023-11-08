#include<stdio.h>

int verifyGeometricProgression(double sequence[],int num){
    double ratio = sequence[1]/sequence[0];
    for(int i = 1; i < num; i++){
        if(sequence[i] != sequence[i-1]*ratio){
        printf("The array is not a geometric progression.\n");
        return 1;
        }
            
    }
    printf("The array is a geometric progression.\n");
    return 0;
}

void printArray(double array[], int num){
    printf("[");
    for(int i = 0; i < num; i++){
        
        printf("%.1f ", array[i]);
    }
    printf("]\n");
}

int main(void){
    int size = 10;
    double sequence1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    printArray(sequence1,size);
    verifyGeometricProgression(sequence1, size);
    double sequence2[] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10};
    printArray(sequence2,size);
    verifyGeometricProgression(sequence2,size);
    double sequence3[] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10};
    printArray(sequence3,size);
    verifyGeometricProgression(sequence3, size);
    double sequence4[] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10};
    printArray(sequence4,size);
    verifyGeometricProgression(sequence4, size);    
    double sequence5[] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10};
    printArray(sequence5,size);
    verifyGeometricProgression(sequence5, size);
    double sequence6[] = {1, 2, 4, 8, 16, 32, 64, 8, 9, 10};
    printArray(sequence6,size);
    verifyGeometricProgression(sequence6, size);
    double sequence7[] = {1, 2, 4, 8, 16, 32, 64, 128, 9, 10};
    printArray(sequence7,size);
    verifyGeometricProgression(sequence7, size);
    double sequence8[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 10};
    printArray(sequence8,size);
    verifyGeometricProgression(sequence8, size);
    double sequence9[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    printArray(sequence9,size);
    verifyGeometricProgression(sequence9, size);

    return 0;
}