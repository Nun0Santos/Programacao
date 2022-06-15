
typedef struct tipoA cliente, *pCliente; 
typedef struct tipoB acesso, *pAcesso; 
typedef struct {int h, m;} hora;

struct tipoA{
    int id;         // Identificador único
    int contador;   // Número de utilizações nesse dia
    pAcesso lista;  // Ponteiro para a lista de acessos
    pCliente prox;  // Ponteiro para o próximo cliente
};
      
struct tipoB{
    hora in, out;   // Horas de entrada e saída
    pAcesso prox;
};