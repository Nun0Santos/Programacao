#include <stdio.h>
#include <stdbool.h>
#include "structs.h"

void guardaDadosCC(cc *carta, int tam);
void guardaDadosDono(dono *d, int tam);
void ex3Parte2(char *filename1, char *filename2);

int main(){
    cc cartas[] ={ 
                  {"Nuno",123456789,334455},
                  {"Pedro",789456123,123456},
                  {"Jonnas",456321789,654321}
                 };

    dono proprietarios[] = { 
                             {"Nuno",123456789,"25-QX-77"},
                             {"Pedro",789456123,"10-SF-20"},
                             {"Jonnas",456321789,"30-PE-45"},
                             {"Kylix",562987456,"45-OA-98"}
                            };
    guardaDadosDono(proprietarios,4);
    guardaDadosCC(cartas, 3);
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
    //fwrite(&tam,sizeof(int),1,f);//Mete o numero de estruturas no inicio
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
    //fwrite(&tam,sizeof(int),1,f);//Mete o numero de estruturas no inicio
    for(int i=0; i<tam; ++i){
        res+=fwrite((d+i), sizeof(dono),1,f);
    }
    printf("Nr de elementos escritos: %d\n",res);
    fclose(f);
}

void ex3Parte2(char *filename1, char *filename2){
    FILE *f,*p,*fp;
    cc cartas;
    dono proprietarios;
    bool valid;
;
    f = fopen(filename1,"rb");//donos
    p = fopen(filename2,"rb");//cartas
    fp = fopen("resumo.txt","wt");

    while( fread(&proprietarios,sizeof(dono),1,f) == 1){
        while( fread(&cartas,sizeof(cc),1,p) == 1){
            valid = false;
            if(proprietarios.nif == cartas.nif){
                fprintf(fp,"%s,\t%d,\t%d\n",proprietarios.nome,proprietarios.nif,cartas.id);
                valid = true;
                break;
            }
        }
        if (!valid)
            fprintf(fp,"%s,\t%d,\t%s\n",proprietarios.nome,proprietarios.nif,"Indisponivel");
        
        rewind(p);
    }
    fclose(f);
    fclose(p);
    fclose(fp);
}