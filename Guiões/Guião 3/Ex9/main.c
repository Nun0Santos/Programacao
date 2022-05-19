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
    int pesosProvas[5],i=0;
    int a;

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

    
    fscanf(fp,"Peso das provas: %d %d %d %d %d",&pesosProvas[i],&pesosProvas[i+1],&pesosProvas[i+2],&pesosProvas[i+3],&pesosProvas[i+4]);
        
    for(int i=0; i<5; ++i)
        printf("Pesos: %d\n",pesosProvas[i]);

    
    





    fclose(fp);
}