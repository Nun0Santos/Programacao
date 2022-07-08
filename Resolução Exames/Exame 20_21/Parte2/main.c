#include <stdio.h>
#include <stdbool.h>
#include "structs.h"

void guardaDadosCC();
void guardaDadosDono();
void ex3Parte2(char *filename1, char *filename2);

int main(){
    cc cartas[] =            { {"Nuno",123456789,334455},
                               {"Pedro",789456123,123456},
                               {"Jonnas",456321789,654321}
                             };

    dono proprietarios[] =   { {"Nuno",123456789,"25-QX-77"},
                               {"Pedro",789456123,"10-SF-20"},
                               {"Jonnas",456321789,"30-PE-45"},
                               {"Kylix",562987456,"45-OA-98"}
                             };
    
    guardaDadosCC(cartas,3);
    guardaDadosDono(proprietarios,4);
    ex3Parte2("infoDonos.dat","infoCartas.dat");
  
};

void guardaDadosCC(cc *carta, int tam){
    FILE *f;
    int i,res=0;

    f = fopen("infoCartas.dat","wb");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para escrita : ");
        return;
    }
    fwrite(&tam,sizeof(int),1,f);//Mete o numero de estruturas no inicio
    for(int i=0; i<tam; ++i){
        res+=fwrite((carta+i), sizeof(cc),1,f);
    }
    printf("Nr de elementos escritos: %d\n",res);
    fclose(f);
}

void guardaDadosDono(dono *d, int tam){
    FILE *f;
    int i,res=0;

    f = fopen("infoDonos.dat","wb");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para escrita : ");
        return;
    }
    fwrite(&tam,sizeof(int),1,f);//Mete o numero de estruturas no inicio
    for(int i=0; i<tam; ++i){
        res+=fwrite((d+i), sizeof(dono),1,f);
    }
    printf("Nr de elementos escritos: %d\n",res);
    fclose(f);
}

void ex3Parte2(char *filename1, char *filename2){
    FILE *f,*p,*fp;
    cc cartas[3];
    dono proprietarios[4];
    bool valid;
    int tmp;
    int elementsDono,elementsCC;
    f = fopen(filename1,"rb");//donos
    p = fopen(filename2,"rb");//cartas

    fp = fopen("resumo.txt","wt");

    fread(&elementsDono,sizeof(int),1,f);
    fread(&elementsCC,sizeof(int),1,p);

    fread(proprietarios,sizeof(dono),elementsDono,f);
    fread(cartas,sizeof(cc),elementsCC,p);

    for(int i = 0; i<elementsDono; ++i){
        valid = false;
        for(int j = 0; j<elementsCC; ++j){
            if(cartas[j].nif == proprietarios[i].nif){
                fprintf(fp,"%s,\t%d,\t%d\n",proprietarios[i].nome,proprietarios[i].nif,cartas[j].id);
                valid = true;
            }
        }
        if (!valid)
            fprintf(fp,"%s,\t%d,\t%s\n",proprietarios[i].nome,proprietarios[i].nif,"Indisponivel");
    }
    fclose(f);
    fclose(p);
    fclose(fp);
}