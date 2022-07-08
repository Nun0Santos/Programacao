#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

void guardaDadosCC(cc *carta, int tam);
void guardaDadosVenda(venda *v, int tam);
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
    P2Ex3("infoCartas.txt","infoVendas.dat","resumo.dat");

};

void  guardaDadosCC(cc *carta, int tam){
    FILE *f;
    int res=0;

    f = fopen("infoCartas.txt","wt");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para escrita : ");
        return;
    }
    fprintf(f,"%d\n",tam);//Mete o numero de estruturas no inicio
    for(int i=0; i<tam; ++i){
        res += fprintf(f,"NIF: %d ; ID: %d\n",carta[i].nif,carta[i].id);
    }
    printf("Nr de elementos escritos: %d\n",res);
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
    //fwrite(&tam,sizeof(int),1,f);//Mete o numero de estruturas no inicio
    for(int i=0; i<tam; ++i){
        res += fwrite((v+1), sizeof(venda),1,f);
    }
    printf("Nr de elementos escritos: %d\n",res);
    fclose(f);
}

void P2Ex3(char *fileName1, char *fileName2, char *fileName3){ //cartas/vendas/resumo
    FILE *f,*p,*fp;
    cc cartas[3];
    venda vendas[4];
    int count =0;

    f = fopen(fileName1,"rt");
    p = fopen(fileName2,"rb");
    fp = fopen(fileName3,"wb");

    while(fread(vendas, sizeof(venda),1,p) == 1){
        while(fread(cartas, sizeof(cc),1,f) == 1){
            printf("%d\t%d\n",vendas->nif,cartas->nif);
            if(vendas->nif == cartas->nif){
               ++count;  
            }
            if(count > 2){
                printf("asdf");
            }
        }
    }
    fclose(f);
    fclose(p);
    fclose(fp);
}