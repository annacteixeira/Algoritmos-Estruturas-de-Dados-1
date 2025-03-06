#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que resolva o seguinte problema: uma cópia “xerox” custa R$ 0,25 por
    folha, mas acima de 100 folhas esse valor cai para R$ 0,20 por unidade. Dado o total de cópias
    (recebidas do usuário), informe o valor a ser pago. Seu programa deve exibir uma mensagem de
    erro em caso de quantidade inválida
*/

int main(){
    int quantidade_copias = 0,continua = 0;
    float total  = 0;

    do{
        printf("\nInforme a quantidade de copias que deseja fazer: ");
        scanf("%d", &quantidade_copias);

        while(quantidade_copias <= 0){
            printf("\nA quantidade de copias nao pode ser menor ou igual a 0. Tente novamente: ");
            scanf("%d", &quantidade_copias);
        }

        if(quantidade_copias <= 100) {
            total = quantidade_copias * 0.25;
            printf("\nO valor para %d quantidade de copias eh %.2f", quantidade_copias, total);
        } else {
            total = quantidade_copias * 0.2;
            printf("\nO valor para %d quantidade de copias eh %.2f", quantidade_copias, total);
        }

        printf("\nVoce deseja calcular novamente? "
                "\n[1] - Sim"
                "\n[0] - Nao\n"
        );
        scanf("%d", &continua);
    } while(continua == 1);

    printf("\n[Saindo...]");
    return 0;
}