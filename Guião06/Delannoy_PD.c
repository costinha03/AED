#include<stdio.h>

int delannoy(int m,int n){
    int memory[1+m][1+n];
    for (int i = 0; i <=m; i++){
        for (int j = 0; j <= n;j++){
            if (i == 0 || j == 0){
                memory[i][j] = 1;   
            }
            else{
                memory[i][j] = memory[i-1][j] + memory[i][j-1] + memory[i-1][j-1];

            }
        }
    }
    return memory[m][n];
}

int main(void){
    int m;
    printf("Insira um número: ");
    scanf("%d", &m);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%-6d   ", delannoy(i, j));
        }
        printf("\n");
    }

    return 0;
}