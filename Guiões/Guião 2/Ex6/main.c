#include "agenda.h"

int main(){
agenda *contactos=NULL;
int total=0;

contactos = malloc(sizeof(agenda));
for(int i=0; i<3; ++i){
    G2Ex6c(contactos,&total);
}

G2Ex6d(contactos,total);

//G2Ex6e(contactos,"Nuno",total);
//Error double free

if(contactos != NULL){
    free(contactos);
}
return 0;
};