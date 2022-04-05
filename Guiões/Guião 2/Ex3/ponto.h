
// alinea a)
typedef struct ponto ponto2D; //struct ponto ou ponto2D
struct ponto{
    int x, y;
};

void printPonto(ponto2D a);
void initPonto(ponto2D* p);
void movePonto(ponto2D* p, int dx, int dy);
int G2Ex1e(ponto2D a, ponto2D b ,ponto2D c);



