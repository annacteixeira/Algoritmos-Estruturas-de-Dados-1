#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um algoritmo que leia o ano de nascimento de uma pessoa e calcule sua idade,
    considerando o ano atual. Para verificar se já fez aniversário no ano atual pergunte se a pessoa já
    fez aniversário, sendo que ela pode entrar com a informação "S"(sim) ou "N" (não). Com isto é
    possível se ter maior precisão sobre a idade. Verifique também se a pessoa já tem idade para
    conseguir Carteira de Habilitação (18 anos ou mais) e imprima a mensagem referente a esta
    checagem. Imprima a idade da pessoa.
*/

int main(){
    const int ano_atual = 2025;
    int ano_nascimento = 0, idade = 0, continua = 0;
    char aniversario;

    do{
        printf("\nQual o ano do seu nascimento? ");
        scanf("%d", &ano_nascimento);
        fflush(stdin);

        while(ano_nascimento < 0){
            printf("\nO ano nao pode ser negativo. Tente novamente: ");
            scanf("%d", &ano_nascimento);
            fflush(stdin);
        }

        printf("\nVoce ja fez aniversario?"
                "\n[S] - Sim"
                "\n[N] - Nao\n\n"
        );

        aniversario = getchar();
        fflush(stdin);

        while(aniversario != 'S' && aniversario != 'N'){
            printf("\nValor invalido. Tente S para sim ou N para nao: ");
            aniversario = getchar();
            fflush(stdin);
        }

        idade = ano_atual - ano_nascimento;

        if(aniversario == 'S'){
            idade = idade + 1;
            printf("\nSua idade eh: %d", idade);
        } else {
            printf("\nSua idade eh: %d", idade);
        }

        printf("\nVoce deseja tentar novamente?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);

    }while(continua == 1);

    printf("\nSaindo...");
}