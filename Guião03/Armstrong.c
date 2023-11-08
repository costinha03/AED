#include <stdio.h>
#include<math.h>
int calcularPotencia(int n, int expoente){
    return pow(n, expoente);
}
int contarAlgarismos(int n){
    int contador = 0;
    while (n > 0) {
        n /= 10;
        contador++;
    }
    return contador;
}
int main(){
    int algarismos;
    int num;
    int potencias[10];

    printf("Insira um número: ");
    scanf("%d", &num);
    algarismos = contarAlgarismos(num);
    for (int i = 0; i <= 9; i++) {
        potencias[i] = calcularPotencia(i,algarismos);
    }    
        

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