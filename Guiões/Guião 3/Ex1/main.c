#include <stdio.h>
#include <stdlib.h>
#include "paragem.h"

void G3Ex1a(char nomeFich[25]);
int G3Ex1b(char nomeFich[25]);

int main(){
    char nome[25] = "cp_ex1.dat";

    G3Ex1a(nome);
    //printf("Soma : %d\n",G3Ex1b(nome));
    
    
}

void G3Ex1a(char nomeFich[25]){
    FILE *fp;
    paragem *p;

    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(p,sizeof(paragem),1,fp) ) != EOF){
        printf("Paragem:\nNome: %s\tMinutos: %d\n",p->nome,p->minutos);
    }
}

int G3Ex1b(char nomeFich[25]){
    FILE *fp;
    paragem *p;
    int soma=0;
    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(p,sizeof(paragem),1,fp) ) != EOF){
        soma +=p->minutos;
    }
    return soma;
}