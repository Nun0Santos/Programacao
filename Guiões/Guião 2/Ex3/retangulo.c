#include "retangulo.h"
#include <stdio.h>

void G2Ex2b(retangulo a){
    printf("Coordenadas:\n");

    printf("Canto inferior esquerdo: x=%d\ty=%d\n",
    a.cantoInferior.x,a.cantoInferior.y);
    printf("Canto superior esquerdo: x=%d\ty=%d\n",
    a.cantoInferior.x,a.cantoInferior.y+a.altura);
    printf("Canto inferior direito: x=%d\ty=%d\n",
    a.cantoInferior.x+a.largura,a.cantoInferior.y);
    printf("Canto superior direito: x=%d\ty=%d\n",
    a.cantoInferior.x+a.largura,a.cantoInferior.y+a.altura);
}

void G2Ex2c(retangulo *a){
    printf("Indique o canto inferior esquerdo (x/y)\n");
    scanf("%d/%d", &a->cantoInferior.x, &a->cantoInferior.y);
    printf("Largura: "); scanf("%d",&a->largura);
    printf("Altura: "); scanf("%d",&a->altura);
}

int G2Ex2d(retangulo a){
    return a.altura*a.largura;
}

int G2Ex2e(retangulo a, ponto2D p){
    if(p.x >a.cantoInferior.x && p.x < a.cantoInferior.x+a.largura){
        if(p.y > a.cantoInferior.y && p.y <a.cantoInferior.y+a.altura){
            return 1;
        }
    }
    return 0;
}

void G2Ex2f(retangulo *a, int x, int y){//x=2 y=3;
    a->cantoInferior.x+=x;
    a->cantoInferior.y+=y;
    /*a->altura = y;
    a->largura = x;*/

}