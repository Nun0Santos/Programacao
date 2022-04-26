#include "agenda.h"

agenda* G2Ex6c(agenda *tab, int *n){
    agenda *p;
   
    char nome[250];
    int numero;
    char numStr[100];
    
    printf("Nome do contacto a adicionar : "); 
    fgets(nome, sizeof(nome)-1,stdin);  
     
    printf("Número do contacto : ");
    fgets(numStr,sizeof(numStr)-1,stdin);
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
    printf("\nHá %d contactos na agenda\n",nContactos);
    if(nContactos == 0){
        printf("Não há contactos a listas\n");
    }
    for(int i=0; i<nContactos; ++i){
        printf("Nome: %s    Contacto: %d\n",tab[i].nome,tab[i].numero);
    }
}

int G2Ex6e(agenda *tab, char *nome, int nContactos){
    if (nContactos == 0)
        printf("\nNão há contactos na Agenda\n");
    
    for(int i=0; i<nContactos; ++i){
        if( strcmp(nome,tab[i].nome ) == 0){
            printf("O número do %s é %d\n",nome,tab[i].numero);
        }
    }
}

int G2Ex6f(agenda *tab, char *nome, int nContactos){
     char numStr[100];
     int numero;
    if (nContactos == 0){
        printf("\nNão há contactos na Agenda\n");
    }

    for(int i = 0; i < nContactos; ++i){
        printf("nome %s\n",nome);
        printf("tab[i].nome %s\n",tab[i].nome);
        printf("tab[i+1].nome %s\n",tab[i+1].nome);

        if( strcmp(nome,tab[i].nome)  == 0){
            printf("Contacto atual : %d\n",tab[i].numero);
            printf("Introduza um novo contacto: ");
            fgets(numStr,sizeof(numStr)-1,stdin);
            numero = atoi(numStr);

            tab[i].numero = numero;
            printf("Novo Contacto : %d\n",tab[i].numero);
            return 1;
        }
        return 0;
    }
}

agenda* G2Ex6g(agenda *tab, char *nome, int *nContactos){
        agenda t,*aux;
        for(int i=0; i<*nContactos; ++i){
            if( ( strcmp(nome,tab[i].nome) ) == 0){
                t = tab[i];
                tab[i] = tab[*nContactos - 1];
                aux = realloc(tab,sizeof(agenda) * (*nContactos-1));
                if (aux != NULL){
                    tab = aux;
                    --(*nContactos);
                }
                else{
                    tab[i] = t;
                }
                return tab;
            }
        }
}