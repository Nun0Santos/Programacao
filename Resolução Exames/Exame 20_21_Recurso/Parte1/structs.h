typedef struct leitura Leitura, *pLeitura;
typedef struct divisao Divisao, *pDivisao;

struct divisao{
    char nome[100];
    int nr_leituras;
    pLeitura leituras;
    pDivisao prox;
};

struct leitura{
    int tipoSensor;
    struct {int h, m;} hora;
    double valor;

};