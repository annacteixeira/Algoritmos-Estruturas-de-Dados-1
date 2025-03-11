#include <stdio.h>
#include <stdlib.h>

/*
    Implemente um algoritmo que peça ao usuário três valores corresponden-
    tes aos lados de um triângulo e verifique se eles formam um triângulo vá-
    lido (a + b > c). Se for um triângulo válido, o algoritmo deve classificá-lo em:
        o Equilátero (todos os lados iguais)
        o Isósceles (dois lados iguais)
        o Escaleno (todos os lados diferentes)
*/

int main()
{
    float lado1 = 0, lado2 = 0, lado3 = 0;
    int continua = 0;

    do {
        printf("\nInforme o valor do primeiro lado do triangulo: ");
        scanf("%f", &lado1);

        printf("\nInforme o valor do segundo lado do triangulo: ");
        scanf("%f", &lado2);

        printf("\nInforme o valor do terceiro lado do triangulo: ");
        scanf("%f", &lado3);

        if((lado1 + lado2) > lado3){
            if(lado1 == lado2 && lado1 == lado3){
                printf("\nTriangulo equilatero");
            } else if(lado1 == lado2 || lado1 == lado3){
                printf("\nTriangulo isosceles");
            } else {
                printf("\nTriangulo escaleno");
            }
        } else {
            printf("\nOs lados fornecidos nao formam um triangulo valido");
        }

        printf("\nVoce deseja testar com outros valores?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);

    }while(continua == 1);

    printf("\nSaindo...\n");
    return 0;
}