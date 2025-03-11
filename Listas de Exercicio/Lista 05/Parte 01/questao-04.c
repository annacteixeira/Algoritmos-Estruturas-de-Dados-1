#include <stdio.h>
#include <stdlib.h>

/*
    Desenvolva um algoritmo que leia um valor n entre 0 e 9 e escreva na tela a tabuada
    correspondente do número. Para o número 4 por exemplo, seria printado:
    4 x 0 = 0
    4 x 1 = 4
    4 x 2 = 8
    ...
    Utilize a estrutura de repetição for.
*/

int main(){
    int n = 0, continua = 0;

    do {
        printf("\nEscolha um numero de 0 a 9 para saber a tabuada: ");
        scanf("%d", &n);

        while(n < 0 || n > 9){
            printf("\nO numero escolhido precisa ser entre 0 e 9. Tente novamente: ");
            scanf("%d", &n);
        }

        for(int i = 0; i <= 10; i++){
            printf("%d x %d = %d\n", n, i, n * i);
        }

        printf("\nDeseja conferir a tabuada de outro numero?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);

    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}