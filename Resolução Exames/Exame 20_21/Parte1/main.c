#include "structs.h"
#include <stdio.h>
#include <stdlib.h>


pCriador criaLista();
void mostraTudo(pCriador c);
int p1Ex1(pCriador p, int gaiola);
pCriador retiraVendidas(pCriador p);

int main(){
    pCriador lista = criaLista();
    mostraTudo(lista);

    printf("\nAves:%d\n",p1Ex1(lista,4));

    lista = retiraVendidas(lista);
    printf("\nDepois:\n");
    mostraTudo(lista);

   return 0;
}

pCriador criaLista(){
    int totC = 4,k=-1,i,j;
    Criador c[] = {{"Jose Silva",2,NULL,NULL},{"Luis Mateus",1,NULL,NULL},{"Ana Costa",3,NULL,NULL},{"Nuno Ferro",1,NULL,NULL}};
    Ave a[] = {{16175,2,02,07,2020,0,0,0,NULL},{19235,4,25,07,2020,22,8,2020,NULL},{22453,3,31,8,2020,29,9,2020,NULL},
               {19723,2,14,8,2020,0,0,0,NULL},{19999,4,21,8,2020,29,8,2020,NULL},{21419,4,29,8,2020,0,0,0,NULL},{23176,3,07,9,2020,0,0,0,NULL}};

    pCriador lista = NULL, novoC;
    pAve novoA;

    for(int i=0; i<totC; ++i)
        k+=c[i].contador;

    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(Criador));
        if(novoC == NULL){
            //libertaTudo(lista);
            return NULL;
        }
        *novoC = c[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(Ave));
            if(novoA == NULL){
                //libertaTudo(lista);
                return NULL;
            }
            *novoA = a[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }    
    }
    return lista;
}

void mostraTudo(pCriador p){
    pAve auxA;
    
    while(p != NULL){
        printf("\nO Utilizador %s tem %d aves a venda\n\n", p->nome, p->contador);
        auxA = p->lista;
        while(auxA != NULL){
            printf("Ave:%d\tGaiola:%d\nData Vender:%d/%d/%d\tData Venda:%d/%d/%d\n\n",auxA->id,auxA->gaiola,auxA->avender.d,auxA->avender.m,auxA->avender.a,auxA->venda.d,auxA->venda.m,auxA->venda.a);
            auxA = auxA->prox;
        }
                    printf("-----------------------------------------------\n");
        p = p->prox;
    }   
}

int p1Ex1(pCriador p, int gaiola){
    pAve auxA;
    int count=0;

    while(p != NULL){
        auxA= p->lista;
        
        while(auxA != NULL){
          if(auxA->gaiola == gaiola)
            ++count;                 
          auxA = auxA->prox;  
        }
        p = p->prox;
    }

    return count;
}

pCriador retiraVendidas(pCriador p){
    pAve atual,ant = NULL;
    
    while (p != NULL){
     
        atual = p->lista;
        while(atual != NULL){
            if(atual->venda.d != 0){// Ave foi vendida
                ant = atual;
                free(ant);
                --p->contador;
            }
            atual = atual->prox;
        }
    }
    p = p->prox;
    return p;
}