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
    int pesosProvas[5],i=0,notasProvas[5];
    int Alunos[5];

    fp = fopen(nameFile,"rt");
    if(fp == NULL)
        return;
    
    while ((c = fgetc(fp)) != EOF)  //Melhor maneira
        putchar(c);

    rewind(fp); // mete o ponteiro fp no inicio do ficheiro
    putchar('\n');

    fscanf(fp,"%*[^:] : %d",&nAlunos);  //%*[^:] le até encontrar : o * permite ler e deitar fora a string
    fscanf(fp,"%*[^:] : %d",&nProvas);

    fscanf(fp,"%*[^:] : %d %d %d %d %d",&pesosProvas[i],&pesosProvas[i+1],&pesosProvas[i+2],&pesosProvas[i+3],&pesosProvas[i+4]);

    for(int i=0; i<nAlunos; ++i){
        fscanf(fp," %*[^:] : %d %d %d %d %d\n",&notasProvas[i],&notasProvas[i+1],&notasProvas[i+2],&notasProvas[i+3],&notasProvas[i+4]);
    }
    

    int j= 0;
    for(int i=0; i<5; ++i){
        Alunos[j] += (float)(pesosProvas[i]/100) * notasProvas[i];
        printf("Notas: %d\tPeso: %.2f\n",notasProvas[i],(float)pesosProvas[i]/100);
        ++j;
        printf("Percentagem: %d\n",Alunos[j]);

    }

    





    fclose(fp);
}