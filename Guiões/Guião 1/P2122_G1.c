#include <stdio.h>
#include <stdlib.h>
#define TAM 7
#define TAM1 10
void G1Ex1();
void G1Ex2();
void G1Ex3();
void printArray();
void G1Ex4();
int G1Ex5();

int main(){
    float v1 = 2.3, v2 = 5.1, v3 = 7.9;
    int tab[TAM1] = {1,3,7,5,2,10,9,7,7,1};
    int pares=0,impares=0, maiorValor=0, posMaiorValor=0;
    int tab1[TAM1] = {1,3,7,5,2,10,9,8,12,6};
    int tab2[TAM] = {1,3,2,10,9,7,4};

    //G1Ex1();
    /*printf("Antes v1=%.2f\tv2=%.2f\tv3=%.2f\t\n",v1,v2,v3);
    G1Ex2(&v1,&v2,&v3);
    printf("Depois v1=%.2f\tv2=%.2f\tv3=%.2f\t\n",v1,v2,v3);*/
    //G1Ex3(tab,TAM1);
    /*G1Ex4(tab,TAM1,&pares,&impares,&maiorValor,&posMaiorValor);
    printf("Existem %d números pares, %d números ímpares. O maior número é o %d e está na posição %d.\n",pares,impares,maiorValor,posMaiorValor);*/
    printf("Comuns: %d\n",G1Ex5(tab1,TAM1,tab2,TAM));

}

void G1Ex1(){
    int a, b, total, *p = &a, *q = &b, *r = &total;
    
    printf("Num1 : ");
    scanf("%d",p);

    printf("Num2 : ");
    scanf("%d",q);

    *r = *p + *q;

    printf("a= %d \t b= %d \t total= %d\n", a, b, total);
}

void G1Ex2(float *a, float *b, float *c){
    *a = *a + *b + *c; //15.3
    *b = *a - *b - *c; //b = 2.3 
    *c = *a - *b - *c; // c = 5.1
    *a = *a - *b - *c; // a = 7.9
}

void G1Ex3(int *a, int dim){
    float soma=0,media=0;

    for(int i=0; i<dim; ++i){
        soma+=a[i];
    }
    media = soma/dim;
    printf("%.2f\n",media);

    for(int i=0; i<dim; ++i){
        if(a[i] < media)
            a[i] = 0;
    }
    printArray(a,dim);
}

void printArray(int *b, int dim){
    for(int i = 0; i < dim; ++i){
        printf("%d\t",b[i]);
    }
    putchar('\n');
}

void G1Ex4(int *t, int tam, int *np, int *ni, int *maior, int *pos){
    *maior = t[0];
    
    for(int i = 0; i < tam; ++i){
        if(t[i] % 2 == 0){
            ++(*np);
        }
        else{
            ++(*ni);
        }
        if(t[i] > *maior){
            *maior = t[i]; 
            *pos = i;
        }
    }
}

int G1Ex5(int *tabA, int tamA, int *tabB, int tamB){
    int aux,cont=0;
    for(int i=0; i<tamA; ++i){
        for(int j=i+1; j<tamA; ++j){
            if(tabA[i] > tabA[j]){
                aux = tabA[i];
                tabA[i] = tabA[j];
                tabA[j] = aux;
            }
        }
    }
     for(int i=0; i<tamB; ++i){
        for(int j=i+1; j<tamB; ++j){
            if(tabB[i] > tabB[j]){
                aux = tabB[i];
                tabB[i] = tabB[j];
                tabB[j] = aux;
            }
        }
    }
    for(int i=0; i<tamA; ++i){
        for(int j=0; j<tamB; ++j){
            if(tabA[i] == tabB[j]){
                ++cont;
            }
        }
    }
    return cont;
}