#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que leia a velocidade máxima permitida em uma avenida e a velocidade
    com que o motorista estava dirigindo nela. Se o motorista estiver dentro do limite de velocidade,
    imprima a mensagem “Motorista respeitou a lei”. Se o motorista tiver ultrapassado a velocidade
    máxima permitida, calcule e imprima o valor da multa a ser cobrada, sabendo que os valores a
    serem cobrados são os seguintes:
    • 50 reais se o motorista ultrapassar em até 10km/h a velocidade permitida (ex: se a
    velocidade máxima for 50km/h e o motorista estiver a 60km/h ou a 56km/h);
    • 100 reais, se o motorista ultrapassar de 11 a 30 km/h a velocidade permitida;
    • 200 reais, se o motorista estiver acima de 30km/h da velocidade permitida.
*/

int main(){
    float velocidade_maxima = 0, velocidade_motorista = 0;
    int continua = 0;

    do {
        printf("\nInforme a velocidade maxima permitida na via: ");
        scanf("%f", &velocidade_maxima);

        while(velocidade_maxima <= 0){
            printf("\nVelocidade invalida. Tente novamente: ");
            scanf("%f", &velocidade_maxima);
        }

        printf("\nInforme a velocidade do motorista: ");
        scanf("%f", & velocidade_motorista);

        while(velocidade_maxima <= 0){
            printf("\nVelocidade invalida. Tente novamente: ");
            scanf("%f", &velocidade_motorista);
        }

        if(velocidade_motorista <= velocidade_maxima){
            printf("\nMotorista respeitou a lei\n");
        } else if(velocidade_motorista > velocidade_maxima && velocidade_motorista <= velocidade_maxima + 10){
            printf("\nMulta de 50 reais\n");
        } else if(velocidade_motorista > velocidade_maxima + 11 && velocidade_motorista <= velocidade_maxima + 30){
            printf("\nMulta de 100 reais\n");
        } else {
            printf("\nMulta de 200 reais\n");
        }

        printf("\nDeseja testar novamente?"
                "\n[1] - Sim"
                "\n[0] - Nao\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);
    
    printf("\nSaindo...\n");
    return 0;
}