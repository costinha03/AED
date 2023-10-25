//Números de Delannoy
//Representam o nº de caminhos até qualquer posição (m,n) permintindo apenas movimentos
//na vertical, horizontal ou diagonal

#include <stdio.h>
int delannoy(int m, int n){
    if(m == 0 || n == 0){
        return 1;
    }else{
        return delannoy(m-1,n) + delannoy(m,n-1) + delannoy(m-1,n-1);
    }
}

int main (void){
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