#include <stdio.h>
#include <stdlib.h>

/*
    Receba uma nota de 0 a 100 e converta-a em conceito:
        o 90-100 → A
        o 80-89 → B
        o 70-79 → C
        o 60-69 → D
        o 0-59 → F
*/

int main()
{
    float nota = 0;
    int continua = 0;

    do{
        printf("\nInforme uma nota de 0 a 100: ");
        scanf("%f", &nota);

        while(nota < 0 || nota > 100){
            printf("\nA nota deve ser um valor de 0 a 100: ");
            scanf("%f", &nota);
        }

        if(nota >= 0 && nota <= 59){
            printf("\nF\n");
        } else if(nota >= 60 && nota <= 69){
            printf("\nD\n");
        } else if(nota >= 70 && nota <= 79){
            printf("\nC\n");
        } else if(nota >= 80 && nota <= 89){
            printf("\nB\n");
        } else {
            printf("\nA\n");
        }

        printf("\nVoce deseja testar com outra nota?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    }while(continua == 1);

    printf("\nSaindo...");
    return 0;
}