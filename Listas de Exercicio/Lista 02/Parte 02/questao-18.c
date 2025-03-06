#include <stdio.h>
#include <stdlib.h>

/*
    Usando o comando switch, escreva um programa que leia (do usuário) um número inteiro entre
    1 e 7 e imprima o dia da semana correspondente ao número. Considere a semana iniciando no
    domingo (1). Caso o usuário digite um valor menor que 1 ou maior que 7, seu programa deve
    exibir a mensagem: “Dia inválido”.
*/

int main(){
    int dia = 0, continua = 0;

    do {
        printf("\nDigite um numero entre 1 e 7 para saber o dia da semana correspondente: ");
        scanf("%d", &dia);

        while(dia < 1 || dia > 7){
            printf("\nValor invalido. Tente um valor entre 1 e 7: ");
            scanf("%d", &dia);
        }

        switch(dia){
            case 1:
                printf("\nDomingo\n");
                break;
            case 2:
                printf("\nSegunda\n");
                break;
            case 3:
                printf("\nTerca\n");
                break;
            case 4:
                printf("\nQuarta\n");
                break;
            case 5:
                printf("\nQuinta\n");
                break;
            case 6:
                printf("\nSexta\n");
                break;
            case 7:
                printf("\nSabado\n");
                break;
            default:
                printf("\nValor invalido.\n");
        }

        printf("\nVoce deseja testar com outro valor?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );

        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...");

}