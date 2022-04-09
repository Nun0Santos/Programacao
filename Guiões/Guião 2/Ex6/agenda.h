#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda agenda;
struct agenda{
    char nome[25];
    int numero;
};

agenda* G2Ex6c(agenda *tab, int *n);
void G2Ex6d(agenda *tab, int nContactos);
int G2Ex6e(agenda *tab, char nome, int nContactos);

