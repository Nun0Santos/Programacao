#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

void guardaDadosCC(cc *carta, int tam);
void guardaDadosVenda(venda *v, int tam);
void printFile(char *nameFile);
void printFileCC(char *nomeFicheiro);
void P2Ex3(char *fileName1, char *fileName2, char *fileName3);

int main(){
 cc cartas[] = { //COMPRADORES
                {123456789,334455},
                {123123123,20945},
                {987654321,1023}
               };

 venda vendas[] = {
                    {9,7,123456789,"25-QX-77"},
                    {21,11,123456789,"AB-00-KL"},
                    {22,11,123123123,"PO-99-LK"},
                    {25,12,142142142,"LG-14-AA"}
                  };

    guardaDadosCC(cartas,3);
    guardaDadosVenda(vendas,4);
    //printFile("infoVendas.dat");
    P2Ex3("infoCartas.txt","infoVendas.dat","resumo.dat");
    printf("\nFicheiro resumo: \n");
    printFileCC("resumo.dat");
};

void  guardaDadosCC(cc *carta, int tam){
    FILE *f;
    int res=0;

    f = fopen("infoCartas.txt","wt");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para escrita : ");
        return;
    }
    for(int i=0; i<tam; ++i){
        res += fprintf(f,"NIF: %d ; ID: %d\n",carta[i].nif,carta[i].id);
    }
    //printf("Nr de elementos escritos: %d\n",res);
    fclose(f);    
}

void guardaDadosVenda(venda *v, int tam){
    FILE *f;
    int res=0;

    f=fopen("infoVendas.dat","wb");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para escrita : ");
        return;
    }
    for(int i=0; i<tam; ++i){
        res += fwrite((v+i), sizeof(venda),1,f);
    }
   //printf("Nr de elementos escritos: %d\n",res);
    fclose(f);
}
void printFile(char *nomeFicheiro) {
    FILE *f;
    struct venda a;
    
    f = fopen(nomeFicheiro, "rb");
    if (f == NULL)
    {
        printf("ERRO no acesso ao ficheiro\n");
        return;
    }

    while (fread(&a, sizeof(struct venda), 1, f) == 1)
        printf("%d/%d ; NIF: %d ; MAT: %s\n", a.data.dia, a.data.mes, a.nif, a.mat);
    
    fclose(f);
}

void P2Ex3(char *fileName1, char *fileName2, char *fileName3){ //cartas/vendas/resumo
    FILE *f,*p,*fp;
    cc cartas;
    venda vendas;
    int count =0;
    int nifCartas, idCartas;
    int a;
    a = -1;

    f = fopen(fileName1,"rt"); //infoCartas
    p = fopen(fileName2,"rb"); //infoVendas
    fp = fopen(fileName3,"wb");//resumo

    while(fscanf(f,"NIF: %d ; ID: %d\n",&nifCartas,&idCartas) != EOF){
        while(fread(&vendas, sizeof(venda),1,p) == 1){
            if(nifCartas == vendas.nif){
               ++count;  
            }
        }
         if(count >= 2){
            fwrite(&nifCartas,sizeof(int),1,fp);
            fwrite(&idCartas,sizeof(int),1,fp);
         }
         else if(count == 0){
            fwrite(&nifCartas,sizeof(int),1,fp);
            fwrite(&a,sizeof(int),1,fp);   
         }  
         count = 0;
         rewind(p);
    }
    fclose(f);
    fclose(p);
    fclose(fp);
}

void printFileCC(char *nomeFicheiro) {
    FILE *f;
    struct cc a;
    
    f = fopen(nomeFicheiro, "rb");
    if (f == NULL)
    {
        printf("ERRO no acesso ao ficheiro\n");
        return;
    }

    while (fread(&a, sizeof(struct cc), 1, f) == 1)
        printf("NIF: %d ; ID:  %d\n", a.nif, a.id);
    fclose(f);
}