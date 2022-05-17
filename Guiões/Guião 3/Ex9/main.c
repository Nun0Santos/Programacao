#include <stdio.h>
#include <stdlib.h>

void G3Ex9(char *nameFile); // Ex tipo de exame 

int main(){

    G3Ex9("notas_ex9.txt");
}

void G3Ex9(char *nameFile){
    FILE *fp;
    int c,nAlunos,nProvas;
    char le[255];

    fp = fopen(nameFile,"rt");
    if(fp == NULL)
        return;
    
    while ((c = fgetc(fp)) != EOF)  //Melhor maneira
        putchar(c);

    rewind(fp); // mete o ponteiro fp no inicio do ficheiro
    

    fscanf(fp,"%*[^:] : %d",&nAlunos);  //%*[^:] le até encontrar : o * permite ler e deitar fora a string
    printf("\nnAluno: %d\n",nAlunos);

    fscanf(fp,"%*[^:] : %d",&nProvas);
    printf("nProvas: %d\n",nProvas);





    fclose(fp);
}