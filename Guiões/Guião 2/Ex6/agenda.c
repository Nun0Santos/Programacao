#include "agenda.h"

agenda* G2Ex6c(agenda *tab, int *n){
    agenda *p;
    agenda *b;
    
    printf("Nome do contacto a adicionar : "); 
    fgets(p->nome,sizeof(agenda),stdin);  
     
    printf("Número do contacto : ");
    scanf("%d",&p->numero);

    printf("nome:%s\tnumero:%d\n",p->nome,p->numero);

    p = realloc(tab,sizeof(agenda) * (*n+1));
    if(p != NULL){
        tab = p;
        printf("nome:%s\tnumero:%d\n",p->nome,p->numero);
        tab[*n] = *p;
        ++(*n);  
    }
    return tab;
};

void G2Ex6d(agenda *tab, int nContactos){
    printf("Há %d contactos na agenda\n",nContactos);
    for(int i=0; i<nContactos; ++i){
        printf("Nome: %s\tContacto: %d\n",tab->nome,tab->numero);
    }
}

int G2Ex6e(agenda *tab, char nome, int nContactos){
    if (nContactos == 0){
        printf("Não há contactos na Agenda\n");
    }

    for(int i=0; i<nContactos; ++i){
        if(nome == tab->nome[i]){
            printf("O número do %c é %d\n",nome,tab->numero);
        }

    }
}
