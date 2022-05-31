#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

void preenche(pno p);
pno G4Ex1b(pno p);
void G4Ex1c(pno p);
void G4Ex1d(pno p, int id, float novoPeso);
pno G4Ex1e(pno p, int id);
pno G4Ex1g(pno p, float imc);
float calculaIMC(float peso, float altura);

int main(){
    pno lista = NULL;

    for(int i = 0; i<3; ++i)
        lista = G4Ex1b(lista);

    printf("Lista: \n");
    G4Ex1c(lista);

    /*G4Ex1d(lista,12,70.3);

    printf("Lista atualizada: \n");
    G4Ex1c(lista);

    lista =  G4Ex1e(lista,12);

    printf("Lista depois de eliminar: \n");
    G4Ex1c(lista);*/

    lista = G4Ex1g(lista, 30);
    putchar("\n");
    printf("Lista depois de eliminar vários: \n");
    G4Ex1c(lista);

    return 0;    
}

void preenche(pno p){

    printf("Nome: ");
    scanf(" %99[^\n]", p->nome);
    printf("Id: ");
    scanf("%d", &(p->id));
    printf("Peso e altura: ");
    scanf("%f %f", &(p->peso), &(p->altura));
    p->prox = NULL;
}

pno G4Ex1b(pno p){
    pno novo, aux;

    novo = malloc(sizeof(no));
    if (novo == NULL){
        printf("Erro na alocacao de memoria\n");
        return p;
    }

    preenche(novo);

    if(p == NULL) // Se a lista estiver vazia
        p = novo;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;

}

void G4Ex1c(pno p){

    while(p != NULL){
        printf("Nome:%s\tId:%d\tPeso:%.2f\tAltura:%.2f\tImc: %.2f\n",p->nome,p->id,p->peso,p->altura,calculaIMC(p->peso,p->altura));
        p = p->prox; 
    }

}

void G4Ex1d(pno p, int id, float novoPeso){
  
    while(p->prox != NULL && p->id != id){
        p = p->prox;
        if(p != NULL)
            p->peso = novoPeso;
        else    
            printf("Id inexistente\n");
    }
}

pno G4Ex1e(pno p, int id){
    pno atual, anterior = NULL;
    atual = p;

    while(atual != NULL && atual->id != id){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL) //Nó não encontrado
        return p;
    if(anterior == NULL)
        p = atual->prox; // 1º nó da lista
    else
        anterior->prox = atual->prox; // caso geral
    
    free(atual);
    return p;
}

pno G4Ex1g(pno p, float limImc){ //elimina vários até um limite, pode sair no exame
    pno atual, anterior = NULL;
    atual = p;
    float imcfunc;

    while(atual != NULL){
        if(calculaIMC(atual->peso,atual->altura) > limImc){
            if(anterior == NULL) // 1º nó da lista
                p = atual->prox;
            else
                anterior->prox = atual->prox;
            free(atual);
            if(anterior == NULL)
                atual = p;
            else    
                atual = anterior->prox;  
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }
    return p;
}

float calculaIMC(float peso, float altura){
    float imc;
    return imc = peso/(altura*altura);
}