#include "strucst.h"
#include <stdio.h>
#include <stdlib.h>


pPaciente criaLista();
void mostraTudo(pPaciente p, int tam);

int main(){
    pPaciente lista = criaLista();
    mostraTudo(lista,4);

}

pPaciente criaLista(){
    Paciente pacientes[] ={ {21,"Ana Silva",3,NULL},
                           {31,"Paulo Mira",1,NULL},
                           {36,"Luis Silva",2,NULL}, 
                           {44,"Beatriz Sa",0,NULL}
                         }; 

    Inter internamentos[] = { {13,4,2,NULL},
                              {13,6,6,NULL},
                              {6,9,-1,NULL},
                              {6,3,12,NULL},
                              {01,01,24,NULL},
                              {25,8,-1,NULL}   
                            };
    
    pPaciente lista = NULL, novoP;
    pInter novoI;
    int totC = 4, k=-1;
    for(int i =0; i<totC; ++i)
        k+=pacientes[i].internamentos;

    for(int i = 0; i<4; ++i){
        novoP = malloc(sizeof(Paciente));
        *novoP = pacientes[i];
        lista = novoP;
    }
    for(int j=0; j<novoP->internamentos; ++j){
        novoI = malloc(sizeof(internamentos));
        *novoI = internamentos[k--];
        novoI->prox = novoP->lista;
        novoP->lista = novoI;
    }

    return lista;

}

void mostraTudo(pPaciente p, int tam){
    pInter auxA;
    auxA = p->lista;
   
    for(int i = 0; i<tam; ++i){
        for(int j=0; j<p->internamentos; ++j){
            while(auxA != NULL){
                printf("Data: %d-%d\tInternamentos: %d\n",auxA[j].din.dia,auxA[j].din.mes,auxA[j].nDias);    
                auxA = auxA->prox;      
            }
        } 
    }   
}