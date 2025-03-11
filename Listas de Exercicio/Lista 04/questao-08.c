#include <stdio.h>
#include <stdlib.h>

/*
    Receba um número de 3 dígitos e verifique se ele é um palíndromo (exemplo: 121, 232)
*/

int main()
{
    int numero = 0, continua = 0, primeiro = 0, terceiro = 0;

    do{
        printf("\nInforme um numero de 3 digitos: ");
        scanf("%d", &numero);

        while(numero < 100 || numero > 999){
            printf("\nO numero deve ter apenas tres digitos. Tente novamente: ");
            scanf("%d", &numero);
        }

        primeiro = numero / 100;
        terceiro = numero % 10;

        if(primeiro == terceiro){
            printf("\nO numero %d eh um palindromo", numero);
        } else {
            printf("\nO numero %d nao eh um palindromo", numero);
        }

        printf("\nDeseja testar novamente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);
    return 0;
}