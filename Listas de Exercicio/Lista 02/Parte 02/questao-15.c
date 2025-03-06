#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que leia o salário de um trabalhador e o valor da prestação de um
    empréstimo. Se a prestação for maior que 20% do salário, imprima: “Empréstimo não concedido”.
    Caso contrário, imprima: “Empréstimo concedido.”
*/

int main(){
    float salario = 0, prestacao = 0;
    int continua = 0;

    do {
        printf("\nInforme o seu salario: ");
        scanf("%f", &salario);

        while(salario <= 0){
            printf("\nO salario nao pode ser 0 ou negativo. Tente novamente: ");
            scanf("%f", &salario);
        }

        printf("\nInforme o valor da prestacao: ");
        scanf("%f", &prestacao);

        while(prestacao <= 0){
            printf("\nO valor da prestacao nao pode ser 0 ou negativo. Tente novamente: ");
            scanf("%f", &prestacao);
        }

        if(prestacao > salario * 0.2){
            printf("\nEmprestimo nao concedido\n");
        } else {
            printf("\nEmprestimo concedido\n");
        }

        printf("\nDeseja simular com outros valores?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\nSaindo...\n");
}