#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Escreva um programa para calcular e imprimir o valor de Y, dado um valor de X:
    y = f(x) =  1, se x <= 1
             = 2, se 1 < x <= 2
             = x^2, se 2 < x <= 3
             = x^3, se x > 3
*/

int main(){
    float x = 0;
    int continua = 0;

    do{
        printf("\nInforme o valor de x para saber o valor de f(x): ");
        scanf("%f", &x);

        if(x <= 1){
            printf("\nf(x) = 1\n");
        } else if(x > 1 && x <= 2){
            printf("\nf(x) = 2\n");
        } else if(x > 2 && x <= 3){
            printf("\nf(x) = %.2f\n", pow(x,2));
        } else {
            printf("\nf(x) = %.2f\n", pow(x, 3));
        }

        printf("\nVoce deseja tentar novamente?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}