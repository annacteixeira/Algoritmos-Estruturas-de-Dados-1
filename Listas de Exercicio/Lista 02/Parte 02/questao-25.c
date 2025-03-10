#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa, utilizando a estrutura SWITCH, que leia um símbolo (caractere) do
    teclado e imprima na saída padrão as seguintes mensagens:
    • "SINAL DE MENOR"
    • "SINAL DE MAIOR"
    • "SINAL DE IGUAL"
    • "OUTRO SINAL"
*/

int main(){
    char sinal;
    int continua = 0;

    do{
        printf("\nInforme um sinal para saber qual o seu tipo: ");
        sinal = getchar();
        fflush(stdin);

        switch(sinal){
            case '<':
                printf("\nSINAL DE MENOR\n");
                break;
            case '>':
                printf("\nSINAL DE MAIOR\n");
                break;
            case '=':
                printf("\nSINAL DE IGUAL\n");
                break;
            default:
                printf("\nOUTRO SINAL\n");
        }

        printf("\nDeseja testar novamente?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
        fflush(stdin);

    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}