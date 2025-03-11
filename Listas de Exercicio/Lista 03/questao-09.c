#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que simule um saque em um caixa eletrônico. O
    usuário deve informar um valor a ser sacado e o programa deve retornar a
    menor quantidade de cédulas possíveis (100, 50, 20, 10, 5, 2, 1)
*/

int main()
{
    int valor = 0, quantidade_100 = 0, quantidade_50 = 0, quantidade_20 = 0;
    int quantidade_10 = 0, quantidade_5 = 0, quantidade_2 = 0, quantidade_1 = 0, continua = 0;

    do {
        printf("\nInforme o valor que deseja sacar: ");
        scanf("%d", &valor);

        while(valor < 0){
            printf("\nImpossivel sacar um valor negativo. Tente novamente: ");
            scanf("%d", &valor);
        }

        quantidade_100 = valor / 100;
        valor = valor % 100;

        quantidade_50 = valor / 50;
        valor = valor % 50;

        quantidade_20 = valor / 20;
        valor = valor % 20;

        quantidade_10 = valor / 10;
        valor = valor % 10;

        quantidade_5 = valor / 5;
        valor = valor % 5;

        quantidade_2 = valor / 2;
        valor = valor % 2;

        quantidade_1 = valor / 1;
        valor = valor % 1;

        if(quantidade_100 > 0){
            printf("\n%d notas de 100", quantidade_100);
        }

        if(quantidade_50 > 0){
            printf("\n%d notas de 50", quantidade_50);
        }

        if(quantidade_20 > 0){
            printf("\n%d notas de 20", quantidade_20);
        }

        if(quantidade_10 > 0){
            printf("\n%d notas de 10", quantidade_10);
        }

        if(quantidade_5 > 0){
            printf("\n%d notas de 5", quantidade_5);
        }

        if(quantidade_2 > 0){
            printf("\n%d notas de 2", quantidade_2);
        }

        if(quantidade_1 > 0){
            printf("\n%d notas de 1", quantidade_1);
        }

        printf("\n\nVoce deseja sacar outro valor?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");

        scanf("%d", &continua);

    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}