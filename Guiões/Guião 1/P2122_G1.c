#include <stdio.h>
#include <stdlib.h>
#define TAM 8
#define TAM2 8
#define TAM1 10

#define L1 3
#define C1 2
#define L2 4
#define C2 3

void G1Ex1();
void G1Ex2();
void G1Ex3();
void printArray();
void G1Ex4();
int  G1Ex5();
void G1Ex7();
int G1Ex8();
int G1Ex9();
int G1Ex10();
int G1Ex11();
void G1Ex14();
void escreve();
int G1Ex15();


int main(){
    float v1 = 2.3, v2 = 5.1, v3 = 7.9;
    int tab[TAM1] = {1,3,7,5,2,10,9,7,7,1};
    int pares=0,impares=0, maiorValor=0, posMaiorValor=0;
    int tab1[TAM1] = {1,3,7,5,20,10,9,8,12,6};
    int tab2[TAM] = {25,25,15,20,1,4,6,2};
    int primMaior , segMaior;
    int mat1[L1][C1] = {{1,2}, 
                        {4,1}, 
                        {5,6}};

    int B[L1][C1] = {{1,2}, 
                    {4,1}, 
                    {5,6}};                    
    char frase[15] ={"Ola aando!"};
    int t1[TAM] = {25,25,15,20,1,4,6,2};
    int t2[TAM2] = {25,25,15,2,1,4,6,2};
    //G1Ex1();
    /*printf("Antes v1=%.2f\tv2=%.2f\tv3=%.2f\t\n",v1,v2,v3);
    G1Ex2(&v1,&v2,&v3);
    printf("Depois v1=%.2f\tv2=%.2f\tv3=%.2f\t\n",v1,v2,v3);*/
    //G1Ex3(tab,TAM1);
    /*G1Ex4(tab,TAM1,&pares,&impares,&maiorValor,&posMaiorValor);
    printf("Existem %d números pares, %d números ímpares. O maior número é o %d e está na posição %d.\n",pares,impares,maiorValor,posMaiorValor);*/
    //printf("Comuns: %d\n",G1Ex5(tab1,TAM1,tab2,TAM));
    /*G1Ex7(tab2,TAM,&primMaior, &segMaior);
    printf("1º Maior:%d\t2º Maior:%d\n",primMaior,segMaior);*/
    //printf("Posição: %d\n",G1Ex8(tab,TAM1));
    //printf("1º-%d\t2º-%d\n",primMaior,segMaior);
    //G1Ex14();
    //printf("%d\n",G1Ex15(L1,C1,mat1));
    //printf("%d\n",G1Ex10(frase));
    printf("%d\n",G1Ex11(t1,TAM,t2,TAM2));
    
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

void G1Ex7(int *tab, int tam, int *prim, int *seg){ 
    int menor=tab[0];
    printArray(tab,tam);

    for(int i=0; i<tam; ++i){
        if(tab[i] < menor){
            *prim=tab[i];
            *seg=tab[i];
        }
    }
    /*if(tab[0] > tab[1]){
        *prim = tab[0];
        *seg = tab[1];
    }else{
        *prim= tab[1];
        *seg = tab[0];
    }*/
    for(int i=0; i<tam; ++i){
        if(tab[i] > *prim){
            *prim = tab[i];
        }
    }
    for(int i =0; i<tam; ++i){
        if(tab[i] > *seg && tab[i] < *prim){
            *seg = tab[i];
        }
    }
}

int G1Ex8(int *tab, int dim){
    int maiorSubida = tab[1] - tab[0], pos=0,j=1;
    for(int i=0; i<dim; ++i){
        j=i+1;
           if((tab[j] - tab[i]) > maiorSubida){
               printf("tab[%d] - tab[%d] : %d\n",j,i,tab[j] - tab[i]);
               maiorSubida  = tab[j] - tab[i];
               pos = j;
           }
           ++j;
    }
    return pos;
}

int G1Ex9(char *tel, char *c){

}

int G1Ex10(char *frase){
    int i=2,cont=0,j=0,x=0;
    char frase2[15];
    while(frase[j] != '\0'){
        if(frase[j] == ' '){
            ++j;
            continue;
        }
        frase2[x] = frase[j];
        ++j;++x;

    }
    printf("%s\n",frase2);

    while(frase2[i] != '\0'){
        if(frase2[i-2] == frase2[i-1] && frase2[i-1] == frase2[i]){
            return 1;
        }
        ++i;
    }
    return 0;
}

int G1Ex11(int a1[], int dim1, int a2[], int dim2){ // Nao esta bem feito
    if(dim1 != dim2){
        return 0;
    }else{
        for(int i = 0; i < dim1; ++i){
            for(int j = 0; j < dim2; ++j){
                if(a1[i] == a2[j]){
                   
                    if(i == dim1-1){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}
void G1Ex14(){
    int mat1[L1][C1] = {{1,2}, {3,4}, {5,6}};
    int mat2[L2][C2] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};

    printf("\nMatriz mat1:\n");
    escreve(L1,C1,mat1);

    printf("\nMatriz mat2:\n");
    escreve(L2,C2,mat2);
}

void escreve(int n_lin, int n_col,int mat1[][n_col]){
   for(int i = 0; i<n_lin; ++i){
        for(int j = 0; j<n_col; ++j){
            printf("%d\t",mat1[i][j]);
        }   
         putchar('\n');
    }
}

int G1Ex15(int nLin, int nCol, int mat[][nCol]){
   
    for(int i=0; i<nLin; ++i){
        for(int j=0; j<nCol; ++j){
        }
    }
    return 1;
}