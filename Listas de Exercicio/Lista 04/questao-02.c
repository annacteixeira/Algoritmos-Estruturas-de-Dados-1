#include <stdio.h>
#include <stdlib.h>

/*
    Solicite a velocidade do carro e informe se o motorista será multado:
        o Até 60 km/h → "Velocidade dentro do limite."
        o Entre 61 e 80 km/h → "Cuidado! Você está acima do limite."
        o Acima de 80 km/h → "Multa aplicada!"
*/

int main()
{
    float velocidade = 0;
    int continua = 0;

    do {
        printf("\nInforme a velocidade do veiculo: ");
        scanf("%f", &velocidade);

        while(velocidade < 0){
            printf("\nA velocidade nao pode ser negativa. Tente novamente: ");
            scanf("%f", &velocidade);
        }

        if(velocidade <= 60){
            printf("\nVelocidade dentro do limite\n");
        } else if(velocidade > 60 && velocidade <= 80){
            printf("\nCuidado! Voce esta acima do limite\n");
        } else {
            printf("\nMulta aplicada!\n");
        }

        printf("\nDeseja testar com outra velocidade?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    }while(continua == 1);

    printf("\nSaindo...");
    return 0;
}