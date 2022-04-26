#include "agenda.h"

int main(){
agenda *contactos=NULL;
int total=0,res;
char nome[255];

contactos = malloc(sizeof(agenda));
if (contactos == NULL){
    printf("Erro na alocação de memória\n");
    return 0;
}

for(int i=0; i<2; ++i){
    contactos = G2Ex6c(contactos,&total);
}

G2Ex6d(contactos,total);

/*printf("Introduza o nome da pessoa a pesqusiar : ");
fgets(nome,sizeof(nome)-1,stdin);

G2Ex6e(contactos,nome,total);*/

printf("Introduza o nome da pessoa para atualizar : ");
fgets(nome,sizeof(nome)-1,stdin);

contactos = G2Ex6f(contactos,nome,total);

printf("\nListagem depois da alteração : \n");
G2Ex6d(contactos,total);


/*printf("Introduza o nome da pesso a eliminar : ");
fgets(nome,sizeof(nome)-1,stdin);*/

/*res = G2Ex6g(contactos,nome,total);
if(res = 1){
    printf("Contacto eliminado com sucesso!\n");
}
else{
    printf("O contacto a eliminar inexistente!\n");
}

printf("\nListagem depois da eliminação : \n");
G2Ex6d(contactos,total);*/


free(contactos);
return 0;
};