//Desenvolva uma função que efetua a permutação circular dos valores de três variáveis inteiras
//passadas como parâmetros. A permutação circular consiste em mover o valor da primeira variável
//para a segunda, o valor da segunda para a terceira e o valor da terceira para a primeira.


#include<stdio.h>


void permute(int* a, int* b, int* c){
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;
    
}

int main(void){
    //pede 3 números ao utilizador
    int a,b,c;
    printf("Insira um número: ");
    scanf("%d",&a);
    printf("Insira um número: ");
    scanf("%d",&b);
    printf("Insira um número: ");
    scanf("%d",&c);
    printf("Os valores inseridos foram: a = %d, b = %d, c = %d\n", a,b,c);
    permute(&a,&b,&c);
    
    printf("Após permutação: a = %d, b = %d, c = %d\n",a,b,c);
    return 0;
}