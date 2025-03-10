#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que leia uma opção de um menu, conforme indicado abaixo e o salário
    atual do funcionário. Calcule e exiba o novo salário. Utilizar o comando SWITCH para escolha do
    item no menu de opções.
    A = aumento de 8% no salário;
    B = aumento de 11% no salário;
    C = aumento fixo no salário de R$ 350,00 se o salário atual for até R$ 1000 e de R$ 200,00 se o
    salário atual for maior que R$ 1000.
*/

int main(){
    char opcao;
    float salario = 0;
    int continua = 0;

    do {
        printf("\n================ CALCULADORA DE SALARIO ================\n"
                "Escolha uma opcao:\n"
                "[A] - Aumento de 8pct no salario\n"
                "[B] - Aumento de 11pct no salario\n"
                "[C] - Aumento fixo no salario de R$ 350,00 se o salario atual for até R$ 1000 e de R$ 200,00 se o salario atual for maior que R$ 1000\n"
        );

        opcao = getchar();
        fflush(stdin);

        printf("\nInforme o salario do funcionario: ");
        scanf("%f", &salario);
        fflush(stdin);

        while(salario < 0){
            printf("\nO salario nao pode ser negativo. Tente novamente: ");
            scanf("%f", &salario);
        }

        switch(opcao){
            case 'A':
                printf("\nNovo salario = %.2f\n", salario + (salario * 0.08));
                break;
            case 'B':
                printf("\nNovo salario = %.2f\n", salario + (salario * 0.11));
                break;
            case 'C':
                if(salario <= 1000){
                    printf("\nNovo salario = %.2f\n", salario + 350);
                } else {
                    printf("\nNovo salario = %.2f\n", salario + 200);
                }
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        printf("\nDeseja calcular novamente?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
        fflush(stdin);
    } while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}