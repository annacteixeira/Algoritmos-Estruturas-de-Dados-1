#include <stdio.h>
#include <stdlib.h>

/*
    Peça o consumo mensal de água em m³ e calcule o valor da conta:
        o Até 10m³ → R$10,00
        o 11 a 30m³ → R$1,50 por m³
        o Acima de 30m³ → R$2,50 por m³
*/ 

int main()
{
    float consumo = 0;
    int continua = 0;

    do{
        printf("\nInforme o consumo mensal de agua em m3: ");
        scanf("%f", &consumo);

        while(consumo < 0){
            printf("\nO consumo nao pode ser negativo. Tente novamente: ");
            scanf("%f", &consumo);
        }

        if(consumo > 0 && consumo <= 10){
            consumo = consumo * 10;
            printf("\nValor = %.2f", consumo);
        } else if(consumo > 10 && consumo <= 30){
            consumo = consumo * 1.5;
            printf("\nValor = %.2f", consumo);
        } else {
            consumo = consumo * 2.5;
            printf("\nValor = %.2f", consumo);
        }

        printf("\nDeseja calcular novamente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...");
    return 0;
}