#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que receba (do usuário) um número e diga se ele está no intervalo entre
    100 e 200.
*/

int main(){
    float n = 0;
    int continua = 0;
    
    do{
        printf("\nInforme um numero: ");
        scanf("%f", &n);

        if(n > 100 && n < 200){
            printf("\n%.2f esta no intervalo entre 100 e 200\n", n);
        } else {
            printf("\n%.2f nao esta no intervalo entre 100 e 200\n", n);
        }

        printf("\nDeseja testar com um novo valor?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...");
}