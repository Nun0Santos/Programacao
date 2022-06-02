#include <stdio.h>
#include <stdlib.h>

void printFile(char *nameFile);

int main(){
    FILE *fp;
    int array[3] = {4,5,6};
    int total = 3;

    fp = fopen("temp.dat","wb");

    fwrite(&total,sizeof(int),1,fp);
    
    for(int i=0; i<total; ++i)
        fwrite(&array[i],sizeof(int),1,fp);
    
    fclose(fp);
     
    printFile("temp.dat");
    return 0;
}

void printFile(char *nameFile){
    FILE *fp;
    int vetor[3],total=0;;

    fp = fopen(nameFile, "rb");
    if(fp == NULL) return;

    fread(&total,sizeof(int),1,fp);
    printf("Total: %d\n",total);
   
    for(int i=0; i<total; ++i){
       fread(&vetor[i],sizeof(int),1,fp);
        printf("Elemento [%d] = %d\n",i,vetor[i]);
    }
    fclose(fp);

}