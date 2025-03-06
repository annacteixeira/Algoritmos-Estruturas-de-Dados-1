#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Escreva um programa que calcule as raízes da equação do 2o grau (ax2 + bx + c); os valores de
    a, b e c são fornecidos pelo usuário.
*/

int main(){
    float a = 0, b = 0, c = 0, delta = 0, raiz_delta = 0, raiz_1 = 0, raiz_2 = 0;

    printf("\nInforme o valor de a: ");
    scanf("%f", &a);
    
    printf("\nInforme o valor de b: ");
    scanf("%f", &b);
    
    printf("\nInforme o valor de c: ");
    scanf("%f", &c);

    delta = pow(b, 2) - (4 * a * c);
    raiz_delta = sqrt(delta);

    raiz_1 = ((b * (-1)) + raiz_delta) / (2 * a);
    raiz_2 = ((b * (-1)) - raiz_delta) / (2 * a);

    printf("\nRaiz x1 = %.2f", raiz_1);
    printf("\nRaiz x2 = %.2f", raiz_2);

    return 0;
}
