#include <stdio.h>
#include <stdlib.h>
#include "concorrente.h"
#define N 4

void G4Ex15a(pno p);
// Funcao para criar a estrutura dinamica com base na informacao do ficheiro de texto
void cria_listas(pno tab[], char *n1)
{
	FILE *f;
	pno novo;
	int i, x, y;

	f = fopen(n1, "r");
	if(f==NULL)
	{
		printf("Erro no acesso ao ficheiro\n");
		return;
	}
	while(fscanf(f, " %d %d", &x, &y) == 2)
	{
		for(i=0; i<y; i++)
		{
			novo = malloc(sizeof(no));
			if(novo == NULL)
			{
				printf("Erro na alocacao de memoria\n");
				fclose(f);
				return;
			}
			fscanf(f, " %d %f %[^\n]", &novo->id, &novo->analise, novo->nome);
			novo->prox = tab[x];
			tab[x] = novo;
		}
	}
	fclose(f);
}


int main()
{
	// Declaracao do array de ponteiros
	pno tab[N] = {NULL};

 
	// Criar ED
	cria_listas(tab, "dados_15.txt");

	// Continuar a partir daqui ...
	G4Ex15a(*tab);

	return 0;
}

void G4Ex15a(pno p){

	while(p != NULL){
		printf("%s\n",p->nome);
		p = p->prox;		
	}
}