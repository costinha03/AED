#include<stdio.h>

int count = 0;

int t2(int n) {
    count++;
    if (n == 1) {
        return 1;
    } else {
        return t2(n/2) + t2((n+1)/2) + n;
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for (int n = 1; n <= num; n++) {
        count = 0;
        int result = t2(n);
        printf("t2(%d) = %d     Calls: %d\n", n, result, count);
        
    }
    return 0;
}