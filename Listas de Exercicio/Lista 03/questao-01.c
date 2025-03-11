#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que verifique se um número inteiro fornecido
    pelo usuário é par ou ímpar
*/

int main()
{
    int n = 0, continua = 0;

    do{
        printf("\nInforme um numero para saber se eh par ou impar: ");
        scanf("%d", &n);

        if(n % 2 == 0){
            printf("\n%d eh um numero par\n", n);
        } else {
            printf("\n%d eh um numero impar\n", n);
        }

        printf("\nVoce deseja testar outro numero?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);

    }while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}