#include <stdio.h>

#define MAX_NUM 1000000

// Função para calcular o fatorial de um número
int calcularFatorial(int n) {
    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    // Pré-calcular e armazenar os fatoriais dos dígitos de 0 a 9
    int fatoriais[10];
    for (int i = 0; i <= 9; i++) {
        fatoriais[i] = calcularFatorial(i);
    }

    printf("Factoriões menores que 10^6 na base 10:\n");

    for (int num = 10; num < MAX_NUM; num++) {
        int originalNum = num;
        int somaFatoriais = 0;

        
        while (originalNum > 0) {
            int digito = originalNum % 10; //Pega no dígito mais à direita
            somaFatoriais += fatoriais[digito]; //Soma o fatorial do dígito mais à direita
            originalNum /= 10; //Descarta o dígito mais à direita
        }

        // Verificar se é um factorião
        if (somaFatoriais == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
