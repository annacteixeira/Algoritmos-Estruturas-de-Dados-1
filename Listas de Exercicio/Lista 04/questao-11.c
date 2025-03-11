#include <stdio.h>
#include <stdlib.h>
#define NUMERO 42

int main(){
    int num_usuario = 0, continua = 0;

    do{
        printf("\nTente adivinhar o meu numero: ");
        scanf("%d", &num_usuario);

        if(num_usuario == NUMERO){
            printf("\nParabens! Voce acertou!\n");
        } else if(num_usuario < NUMERO){
            printf("\nO numero que voce informou eh menor que o meu\n");
        } else {
            printf("\nO numero que voce informou eh maior que o meu\n");
        }

        printf("\nQuer tentar de novo?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}