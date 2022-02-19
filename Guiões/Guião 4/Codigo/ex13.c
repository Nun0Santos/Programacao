#include <stdio.h>
#include <stdlib.h>

typedef struct tipoA cliente, *pCliente; 
typedef struct tipoB acesso, *pAcesso; 

typedef struct {int h, m;} hora;

struct tipoA{
    int id;         // Identificador único
    int contador;   // Número de utilizações nesse dia
    pAcesso lista;  // Ponteiro para a lista de acessos
    pCliente prox;  // Ponteiro para o próximo cliente
};
      
struct tipoB{
    hora in, out;   // Horas de entrada e saída
    pAcesso prox;
};

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
    // Chamar as funções aqui
    
    libertaTudo(lista);  
    return 0;
}