#include <stdio.h>
#include <stdlib.h>

/*
    Receba três números e os exiba em ordem crescente
*/

int main()
{
    float n1 = 0, n2 = 0, n3 = 0, maior = 0, meio = 0, menor = 0;
    int continua = 0;

    do {
        printf("\nInforme o primeiro numero: ");
        scanf("%f", &n1);

        printf("\nInforme o segundo numero: ");
        scanf("%f", &n2);

        printf("\nInforme o terceiro numero: ");
        scanf("%f", &n3);

        if(n1 > n2 && n1 > n3){
            maior = n1;
            if(n2 > n3){
                meio = n2;
                menor = n3;
            } else {
                meio = n3;
                menor = n2;
            }
        } else if (n2 > n1 && n2 > n3){
            maior = n2;
            if(n1 > n3){
                meio = n1;
                menor = n3;
            } else {
                meio = n3;
                menor = n1;
            }
        } else {
            maior = n3;
            if(n1 > n2){
                meio = n1;
                menor = n2;
            } else {
                meio = n2;
                menor = n1;
            }
        }

        printf("\nOrdem crescente = %.2f, %.2f, %.2f\n", menor, meio, maior);


        printf("\nVoce deseja testar com outros valores?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...");
    return 0;
}