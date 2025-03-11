#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que solicite uma nota ao usuário e verifique se
    ela está dentro do intervalo válido (0 a 10). Caso esteja fora do intervalo, o
    programa deve exibir uma mensagem de erro.
*/

int main()
{
    int n = 0, continua = 0;

    do{
        printf("\nInforme uma nota de 0 a 10: ");
        scanf("%d", &n);

        if(n < 0 || n > 10){
            printf("\nErro! Nota invalida.");
        } else {
            printf("\nNota valida!");
        }

        printf("\nVoce deseja testar uma nova nota? "
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);

    }while(continua == 1);
    printf("\nSaindo...\n");
    return 0;
}