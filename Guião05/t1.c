#include <stdio.h>

int count = 0;

int t1(int n) {
    count++;
    if (n == 1) {
        return 1;
    } else {
        return n + t1(n/2);
    }
}


int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for (int n = 1; n <= num; n++) {
        count = 0;
        int result1 = t1(n);
        printf("t1(%d) = %d     Calls: %d\n", n, result1, count);
        
    }
    return 0;
}