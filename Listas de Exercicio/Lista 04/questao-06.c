#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Peça um nome de usuário e uma senha. Se o login for "admin" e a senha
    "1234", exiba "Acesso permitido". Caso contrário, exiba "Acesso negado"
*/

int main()
{
    char login[30];
    char senha[30];

    char login_correto[] = "admin";
    char senha_correta[] = "1234";

    int continua = 0;

    do {
        printf("\nInforme o login: ");
        fgets(login, sizeof(login), stdin);
        login[strcspn(login, "\n")] = 0;
        fflush(stdin);


        printf("\nInforme a senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = 0;
        fflush(stdin);

        if(strcmp(login, login_correto) == 0 && strcmp(senha, senha_correta) == 0){
            printf("\nAcesso permitido");
        } else {
            printf("\nAcesso negado");
        }

        printf("\nDeseja tentar logar novamente?"
               "\n[1] - Sim"
               "\n[0] - Nao\n\n"
        );

        scanf("%d", &continua);
        fflush(stdin);
    } while(continua == 1);

    printf("\nSaindo...");
    return 0;
}