#include <stdio.h>
#include <stdlib.h>

/*
    Receba um número inteiro e informe se ele é primo ou não (usando apenas
    estruturas condicionais, sem laços)
*/

int main(){
    int numero = 0, continua = 0;

    do{
        printf("\nInforme um numero para saber se eh primo: ");
        scanf("%d", &numero);

        if(numero <= 1){
            printf("\nNao eh primo\n");
        } else if(numero == 2 || numero == 3 || numero == 5 || numero == 7){
            printf("\nEh primo\n");
        } else if(numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0){
            printf("\nNao eh primo\n");
        } else {
            printf("\nEh primo\n");
        }

        printf("\nDeseja testar outro numero?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}