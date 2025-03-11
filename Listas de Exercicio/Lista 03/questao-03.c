#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que peça a idade do usuário e classifique-a nas
    seguintes categorias:
        o Criança (0-12 anos)
        o Adolescente (13-17 anos)
        o Adulto (18-59 anos)
        o Idoso (60+ anos)
*/

int main()
{
    int idade = 0, continua = 0;

    do{
        printf("\nInforme a sua idade: ");
        scanf("%d", &idade);

        while(idade < 0){
            printf("\nA idade nao pode ser negativa. Tente novamente: ");
            scanf("%d", &idade);
        }

        if(idade >= 0 && idade <= 12){
            printf("\nCrianca");
        } else if(idade >= 13 && idade <= 17){
            printf("\nAdolescente");
        } else if(idade >=18 && idade <= 59){
            printf("\nAdulto");
        } else {
            printf("\nIdoso");
        }

        printf("\nVoce deseja testar com uma idade diferente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);

    }while(continua == 1);

    printf("\nSaindo...");
    return 0;
}