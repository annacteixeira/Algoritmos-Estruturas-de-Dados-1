#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que solicite dois números ao usuário e exiba qual
    é o maior.
*/

int main()
{
    int n1 = 0, n2 = 0, continua = 0;

    do{
        printf("\nInforme o primeiro numero: ");
        scanf("%d", &n1);

        printf("\nInforme o segundo numero: ");
        scanf("%d", &n2);

        if(n1 > n2){
            printf("\nO numero %d eh maior que %d\n", n1, n2);
        } else {
            printf("\nO numero %d eh maior que %d\n", n2, n1);
        }

        printf("\nVoce deseja testar com outros numeros?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);
    }while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}