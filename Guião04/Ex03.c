#include<stdio.h>

int verifySum(int sequence[],int num){
    int count = 0;
    if (num > 2)
    {
        for(int i = 0; i < num-1; i++){
        if(sequence[i + 2] == sequence[i + 1] + sequence[i]){
        count ++;
        }
            
    }
    return count;}
    else 
    {    
        printf("Introduza uma sequência com mais elementos\n");
    return -1;    
    }
}

void printArray(int array[], int num){
    printf("[");
    for(int i = 0; i < num; i++){
       printf("%d ", array[i]);
    }
    printf("]\n");
}

int main(void){
    int size = 10;
    int sequence1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    printArray(sequence1, size);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence1, size));
    int sequence2[] = {1, 2, 1, 4, 5, 6, 7, 8, 9,10};
    printArray(sequence2,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence2, size));
    int sequence3[] = {1, 2, 1, 3, 2, 6, 7, 8, 9,10};
    printArray(sequence3,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence3, size));
    int sequence4[] = {0, 2, 2, 0, 3, 3, 0, 4, 4, 0};
    printArray(sequence4,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence4, size));
    int sequence5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printArray(sequence5,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence5, size));
    
    int size5 = 5;
    int sequence6[] = {1, 2, 3, 4, 5};
    printArray(sequence6, size5);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence5, size5));

    int size20 = 20;
    int sequence20[] = {1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10};
    printArray(sequence20, size20);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence20, size20));

    int size30 = 30;
    int sequence30[] = {1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10};
    printArray(sequence30, size30);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence30, size30));

    int size40 = 40;
    int sequence40[] = {1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10,
                        1, 2, 1, 4, 5, 6, 7, 8, 9, 10};
    printArray(sequence40, size40);
    printf("Number of elements that are the sum of their neighbors: %d\n", verifySum(sequence40, size40));

    return 0;
}