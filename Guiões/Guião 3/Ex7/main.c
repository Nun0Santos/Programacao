#include <stdio.h>
#include <stdlib.h>

void G3Ex7(char *nameFile, int linha);

int main(){

    G3Ex7("test",2);
}

void G3Ex7(char *nameFile, int linha){
    FILE *fp;
    int c,cont=1;
    char st[255];
    
    fp = fopen(nameFile,"rt");
    if(fp == NULL)
        return;
    
    /*while(fgets(st,sizeof(st),fp) != NULL){ //Se a linha for > 255 ele come
        ++cont;
        if(cont == linha){
           printf("%s\n",st);
        }
    }*/

     while( (c = fgetc(fp) ) != EOF){ // Melhor maneira
        if(c == '\n')
            ++cont;
        if(cont == linha)
           putchar(c);
    }
    fclose(fp);
}