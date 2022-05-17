#include <stdio.h>
#include <stdlib.h>

void G3Ex4(char *nameFile);

int main(){

    G3Ex4("test");
}

void G3Ex4(char *nameFile){
    FILE *fp;
    int c;
    char le[255];

    fp = fopen(nameFile,"rt");
    if(fp == NULL)
        return;
    
    while ((c = fgetc(fp)) != EOF)  //Melhor maneira
        putchar(c);

    /*while(fgets(le,sizeof(le),fp) != NULL)
        printf("%s\n",le);*/
    
    fclose(fp);
}