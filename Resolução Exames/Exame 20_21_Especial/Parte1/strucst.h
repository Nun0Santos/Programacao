typedef struct paciente Paciente, *pPaciente;
typedef struct internamento Inter, *pInter;
typedef struct {int dia, mes;} data;

struct paciente{
    int id;
    char nome[100];
    int internamentos;
    pInter lista;
};

struct internamento{
    data din;
    int nDias;
    pInter prox;
};
