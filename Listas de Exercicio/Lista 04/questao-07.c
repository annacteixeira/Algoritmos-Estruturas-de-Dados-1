#include <stdio.h>
#include <stdlib.h>

/*
    Receba três notas e seus respectivos pesos, calcule a média ponderada e
    exiba a classificação:
        o Média ≥ 7 → "Aprovado"
        o Média entre 5 e 6.9 → "Recuperação"
        o Média < 5 → "Reprovado"
*/

int main()
{
    float n1 = 0, n2 = 0, n3 = 0, p1 = 0, p2 = 0, p3 = 0, media_ponderada = 0;
    int continua = 0;

    do {
        printf("\nInforme a primeira nota: ");
        scanf("%f", &n1);

        printf("\nInforme o peso da primeira nota: ");
        scanf("%f", &p1);

        while(n1 < 0 || p1 < 0){
            printf("\nA nota nem o peso podem ser negativos. Tente novamente: ");
            printf("\nPrimeira nota: ");
            scanf("%f", &n1);

            printf("\nPeso da primeira nota: ");
            scanf("%f", &p1);
        }

        printf("\nInforme a segunda nota: ");
        scanf("%f", &n2);

        printf("\nInforme o peso da segunda nota: ");
        scanf("%f", &p2);

        while(n2 < 0 || p2 < 0){
            printf("\nA nota nem o peso podem ser negativos. Tente novamente: ");
            printf("\nSegunda nota: ");
            scanf("%f", &n2);

            printf("\nPeso da segunda nota: ");
            scanf("%f", &p2);
        }

        printf("\nInforme a terceira nota: ");
        scanf("%f", &n3);

        printf("\nInforme o peso da teceira nota: ");
        scanf("%f", &p3);

        while(n3 < 0 || p3 < 0){
            printf("\nA nota nem o peso podem ser negativos. Tente novamente: ");
            printf("\nTerceira nota: ");
            scanf("%f", &n3);

            printf("\nPeso da terceira nota: ");
            scanf("%f", &p3);
        }

        media_ponderada = (n1 + n2 + n3) / (p1 + p2 + p3);

        if(media_ponderada >= 7){
            printf("\nAprovado\n");
        } else if(media_ponderada >= 5 && media_ponderada <= 6.9){
            printf("\nRecuperacao\n");
        } else {
            printf("\nReprovado\n");
        }

        printf("\nDeseja testar novamente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);

    } while(continua == 1);

    printf("\nSaindo...");
    return 0;
}