#include "ponto.h"

typedef struct retangulo retangulo;
struct retangulo{
    ponto2D cantoInferior;
    int largura;
    int altura;
};

void G2Ex2b(retangulo a);
void G2Ex2c(retangulo *a);
int G2Ex2d(retangulo a);
int G2Ex2e(retangulo a, ponto2D p);
void G2Ex2f(retangulo *a, int x, int y);
