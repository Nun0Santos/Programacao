
#include <stdio.h>
#include "ponto.h"

// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D* p){
    printf("x: \n");
    scanf("%d",&p->x);
    
    printf("y: \n");
    scanf("%d",&p->y);
}

//alinea d)
void movePonto(ponto2D* p, int dx, int dy){
    p->x += dx;
    p->y += dy;
}

//alinea e)
int G2Ex1e(ponto2D a, ponto2D b ,ponto2D c){
    
};