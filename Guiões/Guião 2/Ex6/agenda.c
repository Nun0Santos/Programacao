#include "agenda.h"

agenda* G2Ex6c(agenda *tab, int *n){
    agenda *p;
   
    char nome[250];
    int numero;
    char numStr[100];
    
    printf("Nome do contacto a adicionar : "); 
    fgets(nome, 24,stdin);  
     
    printf("Número do contacto : ");
    fgets(numStr,sizeof(numStr),stdin);
    numero = atoi(numStr);

    p = realloc(tab, sizeof(agenda) * (*n+1));
    if(p != NULL){
        tab = p;
        strcpy(tab[*n].nome, nome);
        tab[*n].numero = numero;
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

/*int G2Ex6e(agenda *tab, char nome, int nContactos){
    if (nContactos == 0){
        printf("Não há contactos na Agenda\n");
    }

    for(int i=0; i<nContactos; ++i){
        if(nome == tab->nome[i]){
            printf("O número do %c é %d\n",nome,tab->numero);
        }

    }
}*/
