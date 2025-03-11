#include <stdio.h>
#include <stdlib.h>

/*
    Peça ao usuário a hora de inicio e de termino de um jogo e calcule a duracao. Se o jogo terminar no dia seguinte, ajuste o cálculo
*/

int main() {
    int dia_inicio = 0, hora_inicio = 0, dia_termino = 0, hora_termino = 0;
    int duracao_horas = 0, duracao_dias = 0, continua = 0;

    do {
        printf("\nInforme o dia de inicio do jogo: ");
        scanf("%d", &dia_inicio);

        printf("Informe o horario de inicio do jogo (0-23): ");
        scanf("%d", &hora_inicio);

        printf("\nInforme o dia de termino do jogo: ");
        scanf("%d", &dia_termino);

        printf("Informe o horario de termino do jogo (0-23): ");
        scanf("%d", &hora_termino);

        if (dia_inicio == dia_termino) {
            if (hora_termino >= hora_inicio) {
                duracao_horas = hora_termino - hora_inicio;
            } else {
                printf("\nErro: O horario de termino nao pode ser antes do horario de inicio no mesmo dia!\n");
                continue;
            }
            duracao_dias = 0;
        } else if (dia_termino > dia_inicio) {
            duracao_dias = dia_termino - dia_inicio;
            duracao_horas = (24 - hora_inicio) + hora_termino + ((duracao_dias - 1) * 24);
        } else {
            printf("\nErro: O dia de termino deve ser igual ou maior que o dia de inicio!\n");
            continue;
        }

        printf("\nduracao total do jogo: %d dia(s) e %d hora(s)\n", duracao_dias, duracao_horas % 24);

        printf("\nDeseja calcular outro jogo?"
                "\n[1] - Sim"
                "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);

    } while (continua == 1);
    
    printf("\nSaindo...\n");
    return 0;
}
