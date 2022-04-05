#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    retangulo r1,r2;
    ponto2D p1;

    r1.largura = 8;
    r1.altura = 2;
    r1.cantoInferior.x = 2;
    r1.cantoInferior.y = 1;

    //G2Ex2b(r1);
    //G2Ex2c(&r2);
    //G2Ex2b(r2);
    //printf("Area = %d\n",G2Ex2d(r1));

    p1.x = 5; p1.y=2;
    printf("%d\n",G2Ex2e(r1,p1));
    printf("Antes da funcao\n");
    G2Ex2b(r1);

    G2Ex2f(&r1,2,3);

    printf("\nDepois da funcao\n");
    G2Ex2b(r1); // ci.x=4 ci.y=4
}