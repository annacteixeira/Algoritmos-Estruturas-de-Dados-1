#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que receba um número inteiro do usuário e diga se ele é par ou ímpar.
*/

int main(){
    int n = 0, continua = 0;

    do{
        printf("\nInforme um numero para saber se eh par ou impar: ");
        scanf("%d", &n);
    
        if(n % 2 == 0){
            printf("\nO numero %d eh par\n", n);
        } else {
            printf("\nO numero %d eh impar\n", n);
        }

        printf("\nVoce deseja testar com outro valor?\n"
                "[1] - Sim\n"
                "[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);
    
    printf("\nSaindo...\n");
    
}