#include <stdio.h>
#define TAM 10

int maiorElemento();

int main(){
  
    int tab[TAM] = {1,4,5,9,8,2,4,6,1,3};
    printf("Maior elemento: %d\n",maiorElemento(tab,TAM));

    return 0;
}


int maiorElemento(int tabela[], int tam){
    int maior=0;
    for(int i =0; i<tam; ++i){
        if(tabela[i] > maior){
            maior=tabela[i];
        }
       
    }
    return maior;



}