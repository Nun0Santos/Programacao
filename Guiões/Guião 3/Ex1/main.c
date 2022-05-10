#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paragem.h"

void G3Ex1a(char nomeFich[25]);
int G3Ex1b(char nomeFich[25]);
int existeParagem(char nomeFich[25], char paragem[25]);
int G3Ex1c(char nomeFich[25], char localA[25], char localB[25]);
int existeLigacao(char nomeFich[25], char *origem, char *destino);

int main(){
    char nome[25] = "cp_ex1.dat";

    G3Ex1a(nome);
    printf("\nTempo total do percurso : %d\n",G3Ex1b(nome));
    printf("\nExiste: %d\n",existeParagem(nome,"Pombal"));
    printf("\nMinutos: %d\n",G3Ex1c(nome,"Coimbra", "Aveiro"));
    printf("\n(Função Professor) Minutos: %d\n",existeLigacao(nome,"Coimbra", "Aveiro"));
    
}

void G3Ex1a(char nomeFich[25]){
    FILE *fp;
    paragem p;

    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(&p,sizeof(paragem),1,fp) ) == 1){
        printf("\nParagem:\nNome: %s\tMinutos: %d\n",p.nome,p.minutos);
    }
    fclose(fp);
}

int G3Ex1b(char nomeFich[25]){
    FILE *fp;
    paragem p;
    int soma=0;
    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(&p,sizeof(paragem),1,fp) )  == 1){
        soma +=p.minutos;
    }
    fclose(fp);
    return soma;
}

int existeParagem(char nomeFich[25], char Paragem[25]){
    FILE *fp;
    paragem p;

    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(&p,sizeof(paragem),1,fp) )  == 1){
       if( (strcmp(p.nome,Paragem) ) == 0){
           return 1;
       }
    }
    fclose(fp);
    return 0;
}

int G3Ex1c(char nomeFich[25], char localA[25], char localB[25]){
    FILE *fp;
    paragem p;
    int i = 0, j = 0,soma = 0;;

    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    int a = existeParagem(nomeFich,localA);
    int b = existeParagem(nomeFich,localB);

    if(a == 0 || b == 0)
        return -1;

    while( (fread(&p,sizeof(paragem),1,fp) )  == 1){
        ++i;
        if(strcmp(p.nome,localA) == 0){
            break;
        }
    }

    fseek(fp,0,SEEK_SET);

    while( (fread(&p,sizeof(paragem),1,fp) )  == 1){
        ++j;
        if(strcmp(p.nome,localB) == 0){
            break;
        }
    }

    if(j < i)
        return -1;

    fseek(fp,0,SEEK_SET);
    while( (fread(&p,sizeof(paragem),1,fp) )  == 1){
        soma += p.minutos;

        if (strcmp(localA, p.nome) == 0) {
            soma = 0;
        }
        if(strcmp(localB, p.nome) == 0) {
            break;
        } 
    }
    return soma;
    fclose(fp);
}

int existeLigacao(char nomeFich[25], char *origem, char *destino){
    FILE *fp;
    paragem a;
    int flag = 0; // 1 -> Origem 2 -> Destino
    int soma = 0;

    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
        return -1;
    }

    while( (fread(&a,sizeof(paragem),1,fp) )  == 1){
        soma += a.minutos;

        if(flag == 0 && strcmp(a.nome,origem) == 0){
               flag = 1;
               soma = 0;
        }
        else if(flag == 1 && strcmp(a.nome,destino) == 0){
            flag = 2;
            break;
        }
    }
    fclose(fp);
    
    if(flag == 2) 
        return soma;
    else
        return -1;
}





