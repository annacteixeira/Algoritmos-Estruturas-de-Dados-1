#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que recebe um ano do usuário e imprime na tela todos os anos bissextos
    do ano 1 até o ano digitado. Utilize a estrutura de repetição while.
*/

int main(){
    int ano = 0, i = 1;

    printf("\nInforme um ano para saber os anos bissextos antes dele: ");
    scanf("%d", &ano);

    while(ano >= i){
        if((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
            printf("\n%d", i);
        }
        i++;
    }

    return 0;
}