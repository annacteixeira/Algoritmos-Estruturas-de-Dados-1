#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Implemente um algoritmo que solicite o peso (kg) e a altura (m) do usuário
    e calcule o IMC (peso / altura²). Classifique o resultado conforme a tabela
    do IMC:
        o Abaixo do peso: IMC < 18.5
        o Peso normal: 18.5 ≤ IMC < 25
        o Sobrepeso: 25 ≤ IMC < 30
        o Obesidade: IMC ≥ 30
*/

int main()
{
    float peso = 0, altura = 0, imc = 0;
    int continua = 0;

    do {
        printf("\nInforme o seu peso em kg: ");
        scanf("%f", &peso);

        printf("\nInforme sua altura em metros: ");
        scanf("%f", &altura);

        while(peso < 0) {
            printf("\nO peso nao pode ser negativo. Tente novamente: ");
            scanf("%f", &peso);
        }

        while(altura < 0) {
            printf("\nA altura nao pode ser negativa. Tente novamente: ");
            scanf("%f", &altura);
        }

        imc = peso / pow(altura, 2);

        if(imc < 18.5){
            printf("\nAbaixo do peso");
        } else if (imc >= 18.5 && imc < 25){
            printf("\nPeso normal");
        } else if(imc >= 25 && imc < 30){
            printf("\nSobrepeso");
        } else {
            printf("\nObesidade");
        }

        printf("\nVoce deseja testar com outros valores?"
               "\n[1] - Sim"
               "\n[0] - Nao\n");
        scanf("%d", &continua);
    }while(continua == 1);
    return 0;
}