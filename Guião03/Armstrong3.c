#include <stdio.h>
#include<math.h>
int calcularPotencia(int n){
    return pow(n, 3);
}
int main(){
    int potencias[10];
    for (int i = 0; i <= 9; i++) {
        potencias[i] = calcularPotencia(i);
    }
    int num;
    do  {
        printf("Insira um número de 3 algarismos: ");
        scanf("%d", &num);
        
        if (num < 100 || num > 999) {
            printf("Número fora do intervalo válido. Tente novamente.\n");
        }
        }
    while (num < 100 || num > 999);

    int originalNum = num;
    int somaPotencias = 0;
    while (originalNum > 0) {
        int digito = originalNum % 10; //Pega no dígito mais à direita
        somaPotencias += potencias[digito]; //Soma o fatorial do dígito mais à direita
        originalNum /= 10; //Descarta o dígito mais à direita
    }
    if (somaPotencias == num) {
        printf("O número %d é número de Armstrong.\n", num);
    } else {
        printf("O número %d não é número de Armstrong.\n", num);
    }
    return 0;
}