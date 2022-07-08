#define DIM 100

typedef struct criador Criador, *pCriador;
typedef struct ave Ave, *pAve;

typedef struct{
    int d;
    int m;
    int a;
}Data;


struct criador{
    char nome[DIM];
    int contador;
    pAve lista;
    pCriador prox;
};

struct ave{
    int id;
    int gaiola;
    Data avender, venda;
    pAve prox;
    };
