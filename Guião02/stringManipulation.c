#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    //pedir ao utilizador 2 strings
    char str1[100];
    printf("Insira uma string: ");
    scanf("%s",str1);

    char str2[100];
    printf("Insira uma string: ");
    scanf("%s",str2);

    //Conte os caracteres da primeira string que são letras do alfabeto.
    int count1 = 0;
    int strlen1 = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        if(isalpha(str1[i])){
            count1++;
             
        }strlen1 ++;
    }

    //Conte os caracteres da segunda string que são letras do alfabeto.
    int count2 = 0;
    int strlen2 = 0;
    for(int i = 0; str2[i] != '\0'; i++){
        if(isalpha(str2[i])){
            count2 ++;
            
        }strlen2 ++;
    }
    //Converta todas as letras maiúsculas, das duas strings, para minúsculas.
    for(int i = 0; str1[i] != '\0'; i++){
        str1[i] = tolower(str1[i]);
    }

    for(int i = 0; str2[i] != '\0'; i++){
        str2[i] = tolower(str2[i]);
    }

    //Compare as duas strings resultantes e escreva uma mensagem indicando que são iguais, ou
    //apresentando as duas strings na sua ordem lexicográfica.
    if (strlen1 == strlen2){
        printf("As duas strings têm o mesmo tamanho.\n");
    }
    else if (strlen1 > strlen2){
        printf("A primeira string é maior que a segunda.\n");
    }
    else{
        printf("A segunda string é maior que a primeira.\n");

    }

    //Crie uma cópia da segunda string.
    char str3[100];
    strcpy(str3,str2);
    //Crie e imprima uma string que resulta da concatenação da segunda string com a sua cópia.
    strcat(str2,str3);
    printf("A concatenação da segunda string com a sua cópia é: %s\n",str2);




}