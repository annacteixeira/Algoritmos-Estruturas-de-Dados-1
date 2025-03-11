#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um algoritmo que declare um número entre 1 e 20 e peça para o usuário adivinhar qual
    é. A cada palpite o programa diz se o número foi mais alto ou mais baixo que o número correto.
    Utilize a estrutura e repetição do-while.
*/

int main(){
    const int num = 11;
    int num_usuario = 0, continua = 0;

    do {
        printf("\nTente adivinhar o meu numero, ele esta entre 1 e 20: ");
        scanf("%d", &num_usuario);

        if(num_usuario == num){
            printf("\nParabens! Voce acertou!\n");
            return 1;
        } else if (num_usuario < num){
            printf("\nO numero que voce tentou eh menor que o meu\n");
        } else {
            printf("\nO numero que voce tentou eh maior que o meu\n");
        }

        printf("\nQuer tentar de novo?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);

    } while(continua == 1);

    printf("\nSaindo...\n\n");

    return 0;
}