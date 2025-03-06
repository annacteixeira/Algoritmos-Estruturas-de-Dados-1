#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um algoritmo que leia 2 números inteiros e faça sua adição. Se o resultado for maior
    ou igual a 10, some 5 a este número. Caso contrário some 7 a ele. Imprima o resultado final.
*/

int main(){
    int n1 = 0, n2 = 0, soma = 0, continua = 0;

    do{
        printf("\nInforme o primeiro numero: ");
        scanf("%d", &n1);
        
        printf("\nInforme o segundo numero: ");
        scanf("%d", &n2);

        soma = n1 + n2;

        if(soma >= 10){
            soma = soma + 5;
            printf("\nResultado: %d\n", soma);
        } else {
            soma = soma + 7;
            printf("\nResultado: %d\n", soma);
        }

        printf("\nDeseja testar com outros valores?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );

        scanf("%d", &continua);
    } while (continua == 1);

    printf("\nSaindo...");
}