#include "utils.h"

int G2Ex3b(retangulo a[], int *p){
    if(*p >= 10){
        printf("Tabela completa\n");
        return 0;
    }
    else{
        G2Ex2c(&a[*p]);
        ++(*p);
        return 1;
    }
}

void G2Ex3c(retangulo a[], int tam){
    printf("Há %d retângulos\n",tam);

    for(int i=0; i<tam; ++i){
        printf("\nRetângulo [%d]:\n",i);
        G2Ex2b(a[i]);
    }
}

int G2Ex3d(retangulo a[], int *total){
    int area[*total],menorArea=0,maiorArea=0;
    if(*total==0){
        printf("Não existe retângulos a eliminar\n");
        return 0;
    }
    for(int i=0; i<*total; ++i){ //calcula area 
        area[i] = G2Ex2d(a[i]);
        printf("Area do retângulo [%d] = %d\n",i,area[i]);
    }
    for(int i=0; i<*total; ++i){ //vê area maior
        if (area[i] > maiorArea){       
            maiorArea = area[i];
        };
    }
    menorArea=maiorArea;
    for(int i=0; i<*total; ++i){ //vê area menor
        if (area[i] < menorArea){       
            menorArea = area[i];  
        };
    }
    for(int i=0; i<*total; ++i){
        if(area[i]==menorArea){
            printf("Retângulo eliminado : [%d]\n",i);
            //a[i] = a[*total-1];
            --(*total);
            return 1;
        };
    }
}

void G2Ex3e(retangulo a[], int *total, int limite){//Ha um problema na parte do eliminar
    int le,esc=0;
  

    if(*total == 0){
        printf("Não existe retângulos a eliminar\n");
    }
    for(le = 0; le<*total; ++le){
        if(G2Ex2d(a[le]) > limite){
            printf("Retângulo [%d] com area = [%d]\n",le,G2Ex2d(a[le]));
            a[esc] = a[le];
            ++esc;
        }
    }
    *total = esc;

}