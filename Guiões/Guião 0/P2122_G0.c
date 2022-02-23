#include <stdio.h>
#define TAM 10

int G0Ex1();
int G0Ex2();
int G0Ex3();
int G0Ex4();
int G0Ex5();

int main(){
  
    int tab[TAM] = {1,2,3,9,8,2,3,4,9,7};
    int tab1[TAM] = {4,6,7,9,1,3,2,10,17};
    printf("Maior elemento: %d\n",G0Ex1(tab,TAM));
    printf("O maior valor surgio na posicao: %d\n",G0Ex2(tab,TAM));
    printf("O maior elemento surge %d vezes\n",G0Ex3(tab,TAM));
    printf("O numero que se repete mais vezes e : %d\n",G0Ex4(tab,TAM));
    printf("Return: %d\n",G0Ex5(tab1,TAM,30));
    return 0;
}

int G0Ex1(int tabela[], int tam){
    int maior=0;
    for(int i =0; i<tam; ++i){
        if(tabela[i] > maior){
            maior=tabela[i];
        }
       
    }
    return maior;
}

int G0Ex2(int tabela[], int tam){
    int pos=0,maior=0;
    maior=G0Ex1(tabela,tam);
    for(int i=0; i<tam; ++i){
        if(tabela[i] == maior){
            pos=i;
            return pos;
        }
    }
}

int G0Ex3(int tabela[], int tam){
    int contador=0,maior=0;
    maior = G0Ex1(tabela,tam); //Retorna o maior elemento
    for(int i=0; i<tam; ++i){
        if(maior == tabela[i]){
            ++contador;
        }
    }
    return contador;
}

int G0Ex4(int tabela[], int tam){ //Nao esta bem feita
    int nRep=0,contador=0;
    for(int i=0; i<tam; ++i){
        for(int j=i+1; j<tam; ++j){
            if(tabela[i] == tabela[j]){
                nRep=tabela[i];
                ++contador;

            }
        }
    }
    return nRep;
}

int G0Ex5(int tab1[], int tam, int num){
    int aux=0,x=0;
    /*for(int i=0; i<tam; ++i){
        for(int j=0; j<tam; ++j){
            if(tab1[i] > tab1[j]){
            tab1[i] = aux;
            tab1[x] = tab1[i+1];
            tab1[i+1] = aux;
            }
        }
    }*/
    for(int i=0; i<tam; ++i){
        if(tab1[i] == num){
            return 1;
        }
    }
    return 0;
}