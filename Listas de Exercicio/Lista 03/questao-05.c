#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que verifique se um ano fornecido pelo usuário é
    bissexto. (Um ano é bissexto se for divisível por 400 ou se for divisível por 4
    e não por 100)
*/

int main()
{
    int ano = 0, continua = 0;

    do{
        printf("\nInforme o ano que deseja saber se eh bissexto: ");
        scanf("%d", &ano);

        while(ano < 0){
            printf("\nO ano nao pode ser negativo. Tente novamente: ");
            scanf("%d", &ano);
        }

        if((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)){
            printf("\nO ano %d eh bissexto", ano);
        } else {
            printf("\nO ano %d nao eh bissexto", ano);
        }

        printf("\nVoce deseja testar com outro ano?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);
    }while(continua == 1);

    printf("\nSaindo...");
    return 0;
}