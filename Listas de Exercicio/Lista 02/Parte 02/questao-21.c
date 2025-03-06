#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um algoritmo que leia da entrada padrão (teclado) a nota de uma prova, entre 0 e 10.
    Verifique em qual faixa de valores a mesma se encaixa e imprima para o usuário a mensagem
    correspondente, conforme a tabela abaixo:

    Faixa das notas             Mensagem
    Nota > = 8 e Nota < = 10    Ótimo
    Nota > = 7 e Nota < 8       Bom
    Nota > = 5 e Nota < 7       Regular
    Nota < 5                    Insatisfatório
*/

int main(){
    float nota = 0;
    int continua = 0;

    do{
        printf("\nInforme uma nota entre 0 e 10: ");
        scanf("%f", &nota);

        while(nota < 0 || nota > 10){
            printf("\nValor invalido. Tente novamente: ");
            scanf("%f", &nota);
        }

        if(nota >= 8 && nota <= 10){
            printf("\nOtimo\n");
        } else if(nota >= 7 && nota < 8){
            printf("\nBom\n");
        } else if(nota >= 5 && nota < 7){
            printf("\nRegular\n");
        } else {
            printf("\nInsatisfatorio\n");
        }

        printf("\nVoce deseja tentar novamente?"
            "\n[1] - Sim"
            "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);
    
    printf("\nSaindo...");
}