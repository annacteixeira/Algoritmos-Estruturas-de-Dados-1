#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que informe a categoria de um jogador de futebol, considerando
    sua idade: infantil (até 13 anos), juvenil (até 17 anos) ou sênior (acima de 17 anos). A idade deve
    ser recebida do usuário.
*/

int main(){
    int idade = 0, continua = 0;

    do {
        printf("\nInforme sua idade para saber a qual categoria pertence: ");
        scanf("%d", &idade);

        while(idade <= 0){
            printf("A idade nao pode ser menor ou igual a zero. Tente novamente: ");
            scanf("%d", &idade);
        }

        if(idade <= 13){
            printf("\nCategoria: infantil");
        } else if(idade > 13 && idade <= 17){
            printf("\nCategoria: juvenil");
        } else {
            printf("\nCategoria: senior");
        }

        printf("\nVoce deseja continuar?"
                "\n[1] - Sim"
                "\n[0] - Nao\n"
        );

        scanf("%d", &continua);

        
    }while(continua == 1);
    
    printf("\nSaindo...");
    return 0;
}