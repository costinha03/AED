#include <stdio.h>

int count = 0;

int t3(int n) {
    count++;
    if (n == 1) {
        return 1;
    } 
    else if (n % 2 != 0 ){
        return t3(n/2) + t3((n+1)/2) + n;
    }
    else{
        return 2 * t3(n / 2);
    }

}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for (int n = 1; n <= num; n++) {
        count = 0;
        int result = t3(n);
        printf("t3(%d) = %d     Calls: %d\n", n, result, count);
        
    }
    return 0;
}