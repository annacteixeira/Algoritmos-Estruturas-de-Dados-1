#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    9. Escreva um programa que leia quatro números inteiros positivos (w, x, y e z) e efetue o cálculo
    de uma das seguintes médias de acordo com o valor de w
*/

int main(){
    int w = 0, x = 0, y = 0, z = 0, continua = 0;
    float media_geometrica = 0, media_ponderada = 0, media_harmonica = 0, media_aritmetica = 0;

    do {

        printf("\nEscolha uma opcao de media para calcular:"
                "\n[1] - Media Geometrica"
                "\n[2] - Media Ponderada"
                "\n[3] - Media Harmonica"
                "\n[4] - Media Aritmetica"
                "\n"
        );

        scanf("%d", &w);
            
        while(w < 1 || w > 4){
            printf("\nOpcao invalida. Tente novamente: ");
            scanf("%d", &w);
        }

        printf("\nInforme o primeiro valor: ");
        scanf("%d", &x);

        while(x < 0){
            printf("\nO valor deve ser positivo. Tente novamente: ");
            scanf("%d", &x);
        }

        printf("\nInforme o segundo valor: ");
        scanf("%d", &y);

        while(y < 0){
            printf("\nO valor deve ser positivo. Tente novamente: ");
            scanf("%d", &y);  
        }

        printf("\nInforme o terceiro valor: ");
        scanf("%d", &z);

        while(z < 0){
            printf("\nO valor deve ser positivo. Tente novamente: ");
            scanf("%d", &z);
        }

        if(w == 1){
            media_geometrica = sqrt(x * y * z);
            printf("\nA media geometrica eh = %.2f", media_geometrica);
        } else if(w == 2){
            media_ponderada = (x + 2 * y + 3 * z) / 6;
            printf("\nA media ponderada eh = %.2f", media_ponderada);
        } else if (w == 3){
            media_harmonica = 3 / ((1 / x) + (1 / y) + (1 / z));
            printf("\nA media harmonica eh = %.2f", media_harmonica);
        } else {
            media_aritmetica = (x + y + z) / 3;
            printf("\nA media aritmetica eh = %.2f", media_aritmetica);
        }

        printf("\nVoce deseja fazer um novo calculo?"
                "\n[1] - Sim"
                "\n[0] - Nao"
                "\n"
        );

        scanf("%d", &continua);

    } while(continua == 1);

    printf("\n[Saindo...]");
    
    return 0;
}