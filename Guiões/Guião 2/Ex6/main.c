#include "agenda.h"

int main(){
agenda *contactos=NULL;
int total=0;

contactos = malloc(sizeof(agenda));

G2Ex6c(contactos,&total);
G2Ex6d(contactos,total);

//G2Ex6e(contactos,nome,total);

if(contactos != NULL){
    free(contactos);
}
return 0;
};