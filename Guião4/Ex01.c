#include<stdio.h>

int countElements(int sequence[],int num){
    int count = 0;
    for(int i = 1; i < num-1; i++){
        if(sequence[i-1] + sequence[i+1] == sequence[i]){
            count++;
        }
    }
    return count;
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
    printArray(sequence1,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", countElements(sequence1, size));
    int sequence2[] = {1, 2, 1, 4, 5, 6, 7, 8, 9,10};
    printArray(sequence2,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", countElements(sequence2, size));
    int sequence3[] = {1, 2, 1, 3, 2, 6, 7, 8, 9,10};
    printArray(sequence3,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", countElements(sequence3, size));
    int sequence4[] = {0, 2, 2, 0, 3, 3, 0, 4, 4, 0};
    printArray(sequence4,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", countElements(sequence4, size));    
    int sequence5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printArray(sequence5,size);
    printf("Number of elements that are the sum of their neighbors: %d\n", countElements(sequence5, size));

    
    return 0;
}