#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    Receba um caractere e informe se ele é uma vogal, uma consoante, um dígito numérico ou um símbolo especial.
        o DICAS:
            1. A função isalpha() da linguagem C verifica se um caractere é
            uma letra.
            2. A função isdigit() da linguagem C verifica se um caractere é um
            digito numérico.
            3. Ambas as funções estão presentes na bibliote ctype.h
*/

/*
isalpha: retorna 1 caso seja uma letra do alfabeto maiúscula, 2 caso seja minúscula, 0 caso não esteja no alfabeto.
*/

int main()
{
    char c;
    int continua;

    do {
        printf("\nInforme um caractere: ");
        c = getchar();
        fflush(stdin);

        if(isdigit(c)){
            printf("\nO caractere %c eh um numero\n", c);
        } else if(isalpha(c) == 1) {
            printf("\nO caractere %c eh uma letra maiuscula\n", c);
        } else if(isalpha(c) == 2){
            printf("\nO caractere %c eh uma letra minuscula\n", c);
        } else {
            printf("\nO caractere %c eh um simbolo especial\n", c);
        }

        printf("\nDeseja testar com outro caractere?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
        fflush(stdin);
    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}