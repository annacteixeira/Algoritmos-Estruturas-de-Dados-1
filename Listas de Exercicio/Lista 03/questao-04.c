#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que receba um número inteiro representando
    um mês (1 a 12) e exiba o nome correspondente do mês.
        o Se o número for 1, exiba "Janeiro".
        o Se for 2, exiba "Fevereiro", e assim por diante até 12, que corres-
        ponde a "Dezembro".
        o Caso o número esteja fora do intervalo 1 a 12, exiba "Mês inválido"
*/

int main()
{
    int mes = 0, continua = 0;

    do {
        printf("\nEscolha um valor de 1 a 12 para saber o mes correspondente: ");
        scanf("%d", &mes);

        while(mes < 1 || mes > 12){
            printf("\nMes invalido. Tente um valor entre 1 e 12: ");
            scanf("%d", &mes);
        }

        switch(mes){
            case 1:
                printf("\nJaneiro");
                break;
            case 2:
                printf("\nFevereiro");
                break;
            case 3:
                printf("\nMarco");
                break;
            case 4:
                printf("\nAbril");
                break;
            case 5:
                printf("\nMaio");
                break;
            case 6:
                printf("\nJunho");
                break;
            case 7:
                printf("\nJulho");
                break;
            case 8:
                printf("\nAgosto");
                break;
            case 9:
                printf("\nSetembro");
                break;
            case 10:
                printf("\nOutubro");
                break;
            case 11:
                printf("\nNovembro");
                break;
            case 12:
                printf("\nDezembro");
                break;
            default:
                printf("\nMes invalido");
        }

        printf("\nVoce deseja testar um mes diferente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);

    } while(continua == 1);

    printf("\nSaindo...\n");


    return 0;
}