#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que peça ao usuário o preço de um produto e
    classifique-o nas categorias:
        o Barato: preço < 50
        o Médio: 50 ≤ preço < 150
        o Caro: preço ≥ 150
*/

int main()
{
    float preco = 0;
    int continua = 0;

    do {
        printf("\nInforme o preco do produto: ");
        scanf("%f", &preco);

        while(preco < 0){
            printf("\nO preco nao pode ser negativo. Tente novamente: ");
            scanf("%f", &preco);
        }

        if(preco < 50){
            printf("\nBarato");
        } else if(preco >= 50 && preco < 150){
            printf("\nMedio");
        } else {
            printf("\nCaro");
        }

        printf("\nDeseja testar outro valor?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);
    }while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}