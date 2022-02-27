#include <stdio.h>
#define MAX 10

typedef struct { // Dados de cada carta
    char nome[100]; // Nome do titular
    int nif; // nif
    int id; // identificacao numerica da carta
}cc;

typedef struct { //Dados de cada novo proprietario de veiculos
    char nome[100]; // Nome proprietario
    int nif; // nif
    char mat[15]; // matricula automovel
}dono;

void guardaDadosCC();
void leDadosCC();
void guardaDadosDono();
void leDadosDono();
void ex3();

int main(){
   cc cartas[MAX] =          {{"Nuno",123456789,334455},{"Pedro",789456123,123456},
                             {"Gil",456321789,654321}};
   
   dono proprietarios[MAX] = {{"Nuno",123456789,"25-QX-77"},{"Pedro",789456123,"10-SF-20"},
                             {"Jonnas",895678456,"30-PE-45"}};
   
   guardaDadosCC(cartas,MAX);
   //leDadosCC(cartas,MAX);
   printf("--------------------------\n");
   guardaDadosDono(proprietarios,MAX);
   //leDadosDono(proprietarios,MAX);

   ex3("infoDonos.dat","infoCartas.dat");
}

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
void leDadosCC(cc *carta, int tam){
    FILE *f;
    int res=0;
    f = fopen("infoCartas.dat","rb");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para leitura : ");
        return;
    }
    fread(&tam,sizeof(int),1,f);
    res = fread(carta,sizeof(cc),tam,f);
    printf("Nr de elementos lidos: %d\n",res);
    /*for(int i=0; i<tam; ++i){
         printf("Nome: %s\tNif: %d\tId: %d\n",carta[i].nome,carta[i].nif,carta[i].id);
    }*/
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

void leDadosDono(dono *d, int tam){
    FILE *f;
    int res=0;
    f = fopen("infoDonos.dat","rb");
    if(f == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro para leitura : ");
        return;
    }
    fread(&tam,sizeof(int),1,f);
    res = fread(d,sizeof(d),tam,f);
    printf("Nr de elementos lidos: %d\n",res);
    /*for(int i=0; i<tam; ++i){
        printf("Nome: %s\tNif: %d\tMat: %s\n",d[i].nome,d[i].nif,d[i].mat);
    }*/
    fclose(f);
}

void ex3(char *nomeFich1, char *nomeFich2){
    FILE *f, *p,*fresumo;
    cc cartas;
    dono proprietarios;
    int tmp;

    f=fopen(nomeFich1,"rb");
    p=fopen(nomeFich2,"rb");
    fresumo=fopen("resumo.txt","wt");
    if(f == NULL && p == NULL && fresumo == NULL){
        perror("[ERRO] ao tentar abrir o ficheiro(s) para leitura (ou escrita) :");
        return;
    }
    while(fread(&proprietarios,sizeof(dono),1,f)){
        tmp=1;
        while(fread(&cartas,sizeof(cc),1,p)){
            printf("cartas : %d\tproprietarios : %d\n",cartas.nif,proprietarios.nif);
            if(cartas.nif == proprietarios.nif){
                fprintf(fresumo,"%s,\t%d,\t%d\n",proprietarios.nome,proprietarios.nif,cartas.id);
                tmp=0;
                break;
            }
        }
        if(tmp == 1){
            fprintf(fresumo,"%s,\t%d,\tindisponivel\n",proprietarios.nome,proprietarios.nif);    
        }
    }
    fclose(f);
    fclose(p);
    fclose(fresumo);
}
