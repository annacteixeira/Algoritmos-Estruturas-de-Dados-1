#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que receba (do usuário) os valores de distância total percorrida e total
    de combustível gasto, calcule e mostre o consumo médio do automóvel.
*/

int main(){
    float distancia = 0, combustivel_gasto = 0, consumo_medio = 0;
    int continua = 0;

    do {
        printf("\nInforme a distancia total percorrida: ");
        scanf("%f", &distancia);

        while(distancia < 0){
            printf("\nA distancia nao pode ser negativa, tente novamente: ");
            scanf("%f", &distancia);
        }

        printf("\nInforme o total de combustivel gasto: ");
        scanf("%f", &combustivel_gasto);

        while(combustivel_gasto < 0){
            printf("\nO combustivel gasto nao pode ser negativo, tente novamente: ");
            scanf("%f", &combustivel_gasto);
        }

        consumo_medio = distancia / combustivel_gasto;

        printf("\nO consumo medio do seu veiculo eh de %.2f km/L\n", consumo_medio);

        printf("\nVoce deseja calcular novamente?"
                "\n[1] - Sim\n"
                "\n[0] - Nao\n"
        );
        scanf("%d", &continua);
    }  while(continua == 1);
    
    printf("\nSaindo...\n");
}