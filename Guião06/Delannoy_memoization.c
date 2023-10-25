#include <stdio.h>

#define Max_m 100
#define Max_n 100

int memory[Max_m][Max_n];
int addCount = 0;

int delannoy(int m, int n) {
    if (memory[m][n] != -1) {
        return memory[m][n];
    } else {
        if (m == 0 || n == 0) {
            memory[m][n] = 1;
        } else {
            memory[m][n] = delannoy(m - 1, n) + delannoy(m, n - 1) + delannoy(m - 1, n - 1);
            addCount +=2;
        }
        return memory[m][n];
    }
}

int main(void) {
    int m;
    printf("Insira um número: ");
    scanf("%d", &m);
    
    for (int i = 0; i <= Max_m; i++) {
        for (int j = 0; j <= Max_n; j++) {
            memory[i][j] = -1;
        }
    }
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%-6d   ", delannoy(i, j));
        }
        printf("\n");
    }
    printf("Número de adições realizadas: %d\n", addCount);
    printf("\n");

    return 0;
}
