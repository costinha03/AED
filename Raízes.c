#include<stdio.h>
#include<math.h>

int main() {
    int n;
    
    printf("Quantas linhas tem a tabela? ");
    scanf("%d", &n);
    
    printf("%-10s%-15s%-15s\n", "Número", "Quadrado", "Raiz Quadrada");
    
    for (int i = 1; i <= n; i++) {
        double square = i * i;
        double squareRoot = sqrt(i);
        printf("%-10d%-15.2f%-15.2f\n", i, square, squareRoot);
    }
    
    return 0;
}