#include <stdio.h>
#include <stdlib.h>

/*
    Um hotel com 75 apartamentos deseja fazer uma promoção especial de final de semana,
    concedendo um desconto de 25% na diária. Com isto, espera aumentar sua taxa de ocupação de
    50% para 80%. Considere um programa que lê o valor de uma diária (normal, sem promoção) e
    imprima:
    a) o valor da diária promocional;
    b) o valor total arrecadado com 80% de ocupação e diária promocional;
    c) o valor total arrecadado com 50% de ocupação e diária normal;
    d) a diferença entre estes dois valores.
*/

int main(){
    float diaria_normal = 0, diaria_promocional = 0, valor_total_promocao = 0, valor_total_normal = 0;
    int continua = 0;

    do {
        printf("\nInforme o valor da diaria sem promocao: ");
        scanf("%f", &diaria_normal);
        fflush(stdin);

        diaria_promocional = diaria_normal - (diaria_normal * 0.25);
        valor_total_promocao = (75 * 0.80) * diaria_promocional;
        valor_total_normal = (75 * 0.5) * diaria_normal;

        printf("\nValor da diaria promocional: R$ %.2f"
                "\nValor arrecadado com 80pct de ocupacao e diaria promocional: R$ %.2f"
                "\nValor arrecadado com 50pct de ocupacao e diaria normal: R$ %.2f"
                "\nDiferenca entre os dois valores: R$ %.2f\n\n", diaria_promocional, valor_total_promocao, valor_total_normal, valor_total_promocao - valor_total_normal
        );

        printf("\nDeseja calcular novamente?"
            "\n[1] - Sim"
            "\n[0] - Nao\n\n"
        );
        scanf("%d", &continua);
        fflush(stdin);

    } while(continua == 1);

    printf("\nSaindo...\n\n");
    return 0;
}