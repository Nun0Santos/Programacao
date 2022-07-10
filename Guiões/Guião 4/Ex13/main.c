#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void G4Ex13a(cliente *c);
void G4EX13b(cliente *c); //acabar esta
int totalMinutos(pAcesso a);
pCliente G4Ex13c(pCliente c);
pCliente acessoParque(pCliente lista, int id, hora x); // importante para o exame

void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso auxA;
    
    while(p != NULL){
        while(p->lista != NULL){
            auxA = p->lista;
            p->lista = p->lista->prox;
            free(auxA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);       
    }   
}

pCliente criaExemploED(){
    int totC = 3, i, j, k=-1;
    cliente a[] = {{13, 2, NULL, NULL},{17,1,NULL,NULL},{22,3,NULL,NULL}};
    acesso b[] = {{{10,20},{11,52},NULL}, {{14,30},{17,2},NULL}, {{10,50},{-1,-1},NULL},
                    {{9,11},{9,12},NULL},{{10,5},{12,0},NULL},{{14,33},{-1,-1},NULL}};
    
    pCliente lista = NULL, novoC;
    pAcesso novoA;
    
    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }  
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }    
    }
    return lista;
}

void mostraTudo(pCliente p){
    pAcesso auxA;
    
    while(p != NULL){
        printf("\nUtilizador com id %d efetuou %d acessos\n", p->id, p->contador);
        auxA = p->lista;
        while(auxA != NULL){
            printf("Entrou as %2.2d:%2.2d. ", auxA->in.h, auxA->in.m);
            if(auxA->out.h == -1)
                printf("Ainda nao saiu do parque\n");
            else
                printf("Saiu as %2.2d:%2.2d\n", auxA->out.h, auxA->out.m);
            auxA = auxA->prox;
        }
        p = p->prox;
    }   
}

int main(){
    
    pCliente lista = criaExemploED();
    
    mostraTudo(lista);
    G4Ex13a(lista);
    //G4EX13b(lista);

    lista = G4Ex13c(lista);
    printf("Depois:\n\n");
    mostraTudo(lista);
    G4Ex13a(lista);

    libertaTudo(lista);  
    return 0;
}

void G4Ex13a(cliente *c){
    pAcesso aux;
    int cont = 0;

    while(c != NULL){
        aux = c-> lista;
        while(aux != NULL){
            if(aux->out.h == -1)
                ++cont;
            aux = aux->prox;
        }
    c = c->prox;
    }   
    printf("\nEstão %d clientes dentro do parque\n",cont);
}

void G4EX13b(cliente *c){
    pAcesso aux;
    int cont = 0,minutos=0,somatorio=0;
    int *id;
    while(c != NULL){
        *id = c->id;
        aux = c-> lista;
        while(aux != NULL){
            if(aux->out.h != -1){
                if(c->id == *id){

                }
                printf("soamtorio : %d\n",somatorio); 
            }               
            aux = aux->prox;
        }
        c = c->prox;
    }   
    //printf("\nCliente com mais minutos: %d\n\n",c->id);
}
int totalMinutos(pAcesso a){
    int totalMinutos=0;
    return totalMinutos = (a->out.h*60 + a->out.m) - (a->in.h*60 + a->in.m);
}

pCliente G4Ex13c(pCliente c){

    pCliente atualCliente = c;
    pCliente ultimoCliente = NULL;
    pCliente tempCliente;
    pAcesso acessoAtual = NULL;
    pAcesso ultimoAcesso;
    pAcesso tempAcesso;

    while(atualCliente != NULL){
        ultimoAcesso = NULL;
        acessoAtual=atualCliente->lista;
        while (acessoAtual != NULL){
            if(acessoAtual->out.h== -1){ //Condicao para eliminar
                if(!ultimoAcesso)
                    atualCliente->lista = acessoAtual->prox;
                else    
                    ultimoAcesso->prox = acessoAtual->prox;
                
                tempAcesso = acessoAtual;
                acessoAtual = acessoAtual->prox;
                free(tempAcesso);
                atualCliente->contador--;
            }
            else{
                ultimoAcesso = acessoAtual;
                acessoAtual = acessoAtual->prox;
            }
        }
        if(atualCliente->contador == 0){
            if(!ultimoCliente)
                c = ultimoCliente->prox;
            else    
                ultimoCliente->prox=atualCliente->prox;
            tempCliente = atualCliente;
            atualCliente = atualCliente->prox;
            free(tempCliente);
        }
        else{
            ultimoCliente = atualCliente;
            atualCliente=atualCliente->prox;
        }
    }
    return c;
}
pCliente acessoParque(pCliente lista, int id, hora x){

    
}