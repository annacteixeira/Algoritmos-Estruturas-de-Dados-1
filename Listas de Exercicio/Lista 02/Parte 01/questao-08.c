#include <stdio.h>
#include <stdlib.h>
/*
    Escreva um programa que calcule a velocidade de queda de um corpo em função do tempo,
    partindo da velocidade zero, considerando a gravidade de diferentes planetas conforme a tabela
    a seguir. Seu programa deve receber do usuário o tempo (em milissegundos) de queda e um
    caractere indicando o planeta em que a queda ocorreu.

    Planeta     Gravidade       Caractere indicativo
    Terra       9,807 m/s2      T
    Vênus       8,87 m/s2       V
    Mercúrio    3,7 m/s2        M

    O tempo informado deve ser maior que zero.
*/
int main(){
    float tempo = 0, velocidade = 0;
    char planeta;
    int continua = 0;

    do {
        printf("\nInforme o planeta que deseja saber a velocidade da queda de um corpo: "
            "\n[T] - Terra"
            "\n[V] - Venus"
            "\n[M] - Mercurio"
            "\n"
        );

        planeta = getchar();
        fflush(stdin);

        while(planeta != 'T' && planeta != 'V' && planeta != 'M'){
            printf("\nPlaneta invalido. Escolha entre T, V ou M: ");
            planeta = getchar();
            fflush(stdin);
        }

        printf("\nInforme o tempo de queda do corpo em ms: ");
        scanf("%f", &tempo);

        while(tempo < 0){
            printf("\nO tempo nao pode ser negativo. Digite outro valor: ");
            scanf("%f", &tempo);
        }

        switch(planeta){
            case 'T':
                velocidade = (tempo / 1000) * 9.807;
                printf("\nA velocidade da queda na Terra para %.2f ms eh = %.2f m/s2 ", tempo, velocidade);
                break;
            case 'V':
                velocidade = (tempo / 1000) * 8.87;
                printf("\nA velocidade da queda em Venus para %.2f ms eh = %.2f m/s2 ", tempo, velocidade);
                break;
            case 'M':
                velocidade = (tempo / 1000) * 3.7;
                printf("\nA velocidade da queda em Mercurio para %.2f ms eh = %.2f m/s2 ", tempo, velocidade);
                break;
            default:
                printf("\nPlaneta invalido. Tente novamente!");
        }

        printf("\nVoce deseja continuar?"
                "\n[1] - Sim"
                "\n[0] - Nao"
                "\n"
        );

        scanf("%d", &continua);
        fflush(stdin);

    }while(continua == 1);
    
    printf("\n[Saindo...]\n");

    return 0;
}