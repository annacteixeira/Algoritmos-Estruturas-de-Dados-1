#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que leia (do usuário) dois números e mostre o maior deles. Se, por acaso,
    os dois números forem iguais, imprima a mensagem “Números iguais”.
*/

int main(){
    int n1 = 0, n2 = 0, continua = 0;

    do{
        printf("\nInforme o primeiro valor: ");
        scanf("%d", &n1);

        printf("\nInforme o segundo valor: ");
        scanf("%d", &n2);

        if(n1 > n2){
            printf("\nO numero %d eh maior que %d", n1, n2);
        } else {
            printf("\nO numero %d eh menor que %d", n1, n2);
        }

        printf("\nVoce deseja testar com outros valores?"
                "\n[1] - Sim"
                "\n[2] - Nao\n"
        );

        scanf("%d", &continua);

    } while(continua == 1);

    printf("\n[Saindo...]\n");
}