#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que, dada a idade de um nadador (recebida do usuário), classifique-o em
    uma das seguintes categorias:
    Categoria   Idade
    Infantil A  5 a 7
    Infantil B  8 a 10
    Juvenil A   11 a 13
    Juvenil B   14 a 17
    Sênior      Maiores de 18 anos
*/

int main(){
    int idade = 0, continua = 0;

    do {
        printf("\nInforme a idade do nadador: ");
        scanf("%d", &idade);

        while(idade < 5){
            printf("\nA idade nao pode ser menor que 5. Tente novamente: ");
            scanf("%d", &idade);
        }

        if(idade >= 5 && idade <= 7){
            printf("\nInfantil A\n");
        } else if(idade >= 8 && idade <= 10){
            printf("\nInfantil B\n");
        } else if(idade >= 11 && idade <= 13){
            printf("\nJuvenil A\n");
        } else if(idade >= 14 && idade <= 17){
            printf("\nJuvenil B\n");
        } else {
            printf("\nSenior\n");
        }

        printf("\nVoce deseja checar com outra idade?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...");
}