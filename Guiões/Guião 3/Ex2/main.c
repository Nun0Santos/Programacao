#include <stdlib.h>
#include <stdio.h>

void printFile(char *nomeFich);
void G3Ex2a(char *nomeFich, int *nElementos, int *soma, float *media);

int main(){
    int nElementos = 0, soma = 0;
    float media = 0;

    printFile("valoresEx2.bin");

    G3Ex2a("valoresEx2.bin",&nElementos,&soma,&media);
    printf("\nnElementos: %d\tSoma: %d\tMedia: %.2f\n",nElementos,soma,media);
    
}

void printFile(char *nomeFich){
    FILE *fp;
    int num;
    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(&num,sizeof(num),1,fp) ) == 1){
        printf("Numeros: %d\n",num);
    }
    fclose(fp);
}

void G3Ex2a(char *nomeFich, int *nElementos, int *soma, float *media ){
    FILE *fp;
    int num;
    fp = fopen(nomeFich,"rb");
    if(fp == NULL){
        perror("Erro ao tentar abrir o ficheiro para leitura ");
    }

    while( (fread(&num,sizeof(int),1,fp) ) == 1){
        *soma +=num;
        ++(*nElementos);
    }
    *media = (float) *soma / *nElementos;

    fclose(fp);
}