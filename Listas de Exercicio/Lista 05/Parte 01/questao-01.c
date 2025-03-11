#include <stdio.h>
#include <stdlib.h>

/*
Codifique o algoritmo abaixo em C e escreva na tela do monitor o valor de x ao final da
execução.
algoritmo
        declare r, x, y, z : inteiro;
        x ← 1;
        y ← 12;
        z ← 0;
        enquanto (z < 5)
            r ← y MOD 3;
            se (r = 0)
            então x ← x+2;
            fimse ;
            y ← y + 5;
            z ← z + 1;
        fim-enquanto;
fim-algoritmo
*/

int main(){
    int r, x, y, z;
    x = 1;
    y = 12;
    z = 0;
    
    while(z < 5){
        r = y % 3;
    
        if(r == 0){
            x = x + 2;
        }

        y = y + 5;
        z = z + 1;
    }

    printf("x = %d", x);
    return 0;
}