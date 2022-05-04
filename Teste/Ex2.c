#include <stdlib.h>
#include <stdio.h>

typedef struct info{
    struct {int dia, mes, ano;} registo;
    int c1, c2, c3;
}dados;

int processa();

void main(){
     dados a[5] = {{{2,5,2020},1,3,5},
                  {{23,5,2021},2,3,50},
                  {{25,5,2022},10,30,15},
                  {{23,5,2020},4,3,51},
                  {{23,5,2019},12,2,5}};
    float x;
    int y;
    y = processa(a, 5, 23, &x);
    printf("%.1f %d\n", x, y);
}

int processa(dados *a, int tam, int alvo, float* p){
    int cont = 0, sum = 0;
    for(int i=0; i<tam; ++i){
        if(a[i].registo.dia == alvo){
            ++cont;
        }
        sum += a[i].c2;
    }
    *p = sum/(float)tam;
    return cont;
}