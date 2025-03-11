#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que leia a altura de 5 homens e 5 mulheres, e imprima a média de altura
    masculina, feminina e geral.
*/

int main(){
    float altura = 0, altura_homens = 0, altura_mulheres = 0, soma = 0;

    for(int i = 1; i < 6; i++){
        printf("\nInforme a altura da mulher num. %d: ", i);
        scanf("%f", &altura);

        altura_mulheres = altura_mulheres + altura;
        soma = soma + altura;
    }

    for(int i = 1; i < 6; i++){
        printf("\nInforme a altura do homem num. %d: ", i);
        scanf("%f", &altura);

        altura_homens = altura_homens + altura;
        soma = soma + altura;
    }

    printf("\nAltura media das mulheres = %.2f", altura_mulheres / 5);
    printf("\nAltura media dos homens = %.2f", altura_homens / 5);
    printf("\nAltura media geral = %.2f", soma / 10);

    return 0;
}