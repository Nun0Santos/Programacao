#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void G3Ex10a(char *nameFile);
void G3Ex10b(char *nameFile);
void G3Ex10c(char *nameFile);
int G3Ex10d(char *nameFile, char *or, char *dest, int valor);

void G3Ex10f(char *nameFile,cliente c1);

int main(){
    cliente c1 = {"Diogo", "Coimbra",123, 20};

    G3Ex10a("Ex10_clientes1.dat");
    //G3Ex10b("Ex10_clientes1.dat");
    /*printf("Lista inversa:\n");
    G3Ex10c("Ex10_clientes1.dat");*/

    /*printf("%d\n",G3Ex10d("Ex10_clientes1.dat","Elsa Ourem","Dinis Pais",50)); 
    printf("Depois de atualizar saldo:\n");
    G3Ex10a("Ex10_clientes1.dat");*/

    G3Ex10f("Ex10_clientes1.dat",c1);
    printf("Lista depois de adicionar: \n");
    G3Ex10a("Ex10_clientes1.dat");

    return 0;
}

void G3Ex10a(char *nameFile){
    FILE *fp;
    cliente c;

    fp = fopen(nameFile,"rb");
    if (fp == NULL)
        printf("Erro ao abrir ficheiro\n");

    while(fread(&c,sizeof(cliente),1,fp) == 1){
        printf("Nome: %s\tMorada: %s\tConta: %d\tMontante: %d\n",c.nome,c.morada,c.conta,c.montante);
    }
    fclose(fp);
}

void G3Ex10b(char *nameFile){
    FILE *fp;
    cliente c;

    fp = fopen(nameFile,"rb");
    if (fp == NULL)
        printf("Erro ao abrir ficheiro\n");
    
    fseek(fp,0,SEEK_END); // posiciona o fp no fim do ficheiro

    printf("Número total de bytes: %lu\n",ftell(fp));
    printf("Número de clientes: %lu\n",ftell(fp)/sizeof(cliente));

}

void G3Ex10c(char *nameFile){
    FILE *fp;
    cliente c;
    int nClientes;

    fp = fopen(nameFile,"rb");
    if (fp == NULL)
        printf("Erro ao abrir ficheiro\n");

    fseek(fp,0,SEEK_END);
    nClientes = ((ftell(fp))/sizeof(cliente));
    fseek(fp,-sizeof(cliente),SEEK_END);

    for(int i=0; i<nClientes; ++i){
        fread(&c,sizeof(cliente),1,fp);
        printf("Nome: %s\tMorada: %s\tConta: %d\tMontante: %d\n",c.nome,c.morada,c.conta,c.montante);      
        fseek(fp,-2*sizeof(cliente),SEEK_CUR);    
                  
    }
    fclose(fp);
}

int G3Ex10d(char *nameFile, char *or, char *dest, int valor){
    FILE *fp;
    cliente c;
    int nClientes;
    int soma;

    fp = fopen(nameFile,"rb+");

    if (fp == NULL)
        printf("Erro ao abrir ficheiro\n");

    while(fread(&c,sizeof(cliente),1,fp) == 1){
        if( strcmp(c.nome,or)  == 0 ){
           c.montante -= valor;
           fseek(fp,-sizeof(cliente),SEEK_SET);
           fwrite(&c,sizeof(cliente),1,fp);
        } 
    }
    fseek(fp,0,SEEK_SET);

    while(fread(&c,sizeof(cliente),1,fp) == 1){
        if(strcmp(c.nome,dest)  == 0){
            c.montante += valor;
            fseek(fp,-sizeof(cliente),SEEK_SET); //leio o cliente que quero atualizar subo para cima e escrevo por cimada estrutura que quero
            fwrite(&c,sizeof(cliente),1,fp);
        }
    }
}
void G3Ex10f(char *nameFile,cliente c1){
    FILE *f;
    FILE *g;
    cliente a;

    f = fopen(nameFile, "rb");if(f==NULL)return;
    g = fopen("temp.dat", "wb");if(g==NULL)fclose(f);return;

    while(fread(&a,sizeof(cliente),1,f) == 1){
        if(strcmp(a.nome,c1.nome) > 0)
            fwrite(&c1,sizeof(cliente),1,g);

        fwrite(&a,sizeof(cliente),1,g);
    }
    fclose(f);
    fclose(g);
    
    remove(nameFile);
    rename("temp.dat",nameFile);
}

