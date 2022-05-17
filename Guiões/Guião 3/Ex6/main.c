#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void G3Ex6(char *nameFile);

int main(){

    G3Ex6("test");
}

void G3Ex6(char *nameFile){
    FILE *fp,*f;
    int c,cont=1;;
    char le[255];

    fp = fopen(nameFile,"rt");
    if(fp == NULL)
        return;

    f = fopen("copia.txt","wt");
    if(f == NULL)
        return;

    /*while(fgets(le,sizeof(le),fp) != NULL) //Mosra no ecrã
        printf("%d. %s",cont++,le);*/
    
    while(fgets(le,sizeof(le),fp) != NULL) //Escreve no fich
        fprintf(f,"%d. %s",cont++,le);

    fclose(fp);
    fclose(f);
}