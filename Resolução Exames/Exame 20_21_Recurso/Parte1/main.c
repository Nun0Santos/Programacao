#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pDivisao criaLista();
void mostraTudo(pDivisao p);
float P1Ex1(pDivisao p, int sensor);

int main(){
    pDivisao p = criaLista();
    mostraTudo(p);
    
    printf("%.1f\n",P1Ex1(p,3));

}

pDivisao criaLista(){ //by Kylix
    Divisao divisoes[] = {
        {"cozinha",5,NULL,NULL},
        {"quarto",3,NULL,NULL},
        {"sala",0,NULL,NULL}
    };
    Leitura leituras[] = {
        {1,8,01,23.1},
        {2,9,34,4.5},
        {6,11,36,9.8},
        {3,12,23,34.5},
        {5,15,22,1016.2},
        {1,9,01,12.2},
        {3,10,17,38.3},
        {5,11,36,1018.0}
    };
    pDivisao pDiv = malloc(sizeof(Divisao));
    pDivisao auxDiv = pDiv;
    auxDiv->prox = malloc(sizeof(Divisao));
    auxDiv = auxDiv->prox;
    auxDiv->prox = malloc(sizeof(Divisao));
    auxDiv = auxDiv->prox;
    auxDiv->prox = NULL;
    auxDiv = pDiv;
    for (int i = 0; i < 3; i++){
        strcpy(auxDiv->nome, divisoes[i].nome);
        auxDiv->nr_leituras = 0;
        auxDiv = auxDiv->prox;
    }
    auxDiv = pDiv;
    auxDiv->leituras = malloc(sizeof(Leitura) * 5);
    for (int i = 0; i < 5; i++)
        memcpy(&auxDiv->leituras[i], &leituras[i], sizeof(Leitura));
    auxDiv->nr_leituras = 5;
    auxDiv = auxDiv->prox;
    auxDiv->leituras = malloc(sizeof(Leitura) * 3);
    for (int i = 5; i < 8; i++)
        memcpy(&auxDiv->leituras[i - 5], &leituras[i], sizeof(Leitura));
    auxDiv->nr_leituras = 3;
    return (pDiv);
}
void mostraTudo(pDivisao p){
    pLeitura auxA;
    
    while(p != NULL){
        printf("\nA %s tem %d leituras\n\n", p->nome, p->nr_leituras);
        auxA = p->leituras;
        for(int i=0; i<p->nr_leituras; ++i){
            printf("Leitura:%d\tData:%d/%d\tValor:%.1f\n",auxA[i].tipoSensor,auxA[i].hora.h,auxA[i].hora.m,auxA[i].valor);
    
        }
        p = p->prox;
    }   
}

float P1Ex1(pDivisao p, int sensor){
    pLeitura leitura;
    float valorAnterior=0.0,valorAtual=0.0;
    int count =0;
    float valores[8];
    int j=0;

    while(p != NULL){
        leitura = p->leituras;
        for(int i = 0; i<p->nr_leituras; ++i){
            if(leitura[i].tipoSensor == sensor){
                printf("%s: %.1f  [%d:%d]\n",p->nome,leitura[i].valor,leitura[i].hora.h,leitura[i].hora.m);
                ++count;
                valores[j] = leitura[i].valor;++j;
            } 
        }
        p = p->prox;
    }
    for(int i = 0; i<j; ++i){
        if(valores[i]>valores[i+1])
            return (float)valores[i];
    }
    return -1.0;
}