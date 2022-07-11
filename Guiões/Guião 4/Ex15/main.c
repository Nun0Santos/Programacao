#include <stdio.h>
#include <stdlib.h>
#include "concorrente.h"
#define N 4

void G4Ex1a(pno p[],int tam);
pno addCorrida(pno p[],int *tam);
pno obtemInfo();
pno addConcorrente(pno p[]);
pno eliminaConcorrente(pno p[]);
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
	int tam = 4;
 
	// Criar ED
	cria_listas(tab, "dados_15.txt");

	// Continuar a partir daqui ...
	G4Ex1a(tab,tam);

	tab[N] = addConcorrente(tab);
	printf("Depois de adicionar:\n");
	G4Ex1a(tab,tam);

	tab[N] = eliminaConcorrente(tab);
	printf("Depois de eliminar :\n");
	G4Ex1a(tab,tam);


	return 0;
}

void G4Ex1a(pno p[],int tam){//array de listas
	pno aux;
	for(int i=0; i<tam; ++i){
		aux =p[i];
		while( aux != NULL){
			printf("Corrida [%d]\tNome:%s\tId:%d\tAlcool:%.2f\n",i,aux->nome,aux->id,aux->analise);
			aux = aux->prox;
		}
		putchar('\n');
	}
	
}

pno addCorrida(pno p[], int *tam){
	pno *novo;

	novo = realloc(p,sizeof(int) * (*tam+1));
	if(novo != NULL){
		p = novo;	
		(*tam)++;
	}
	return *p;
}

pno addConcorrente(pno p[]){
	pno aux = *p;
	pno novo;
		while( aux->prox != NULL){
			aux = aux->prox;
		}
		novo = malloc(sizeof(no));
		aux->prox = novo;
		novo->id = 144;
		novo->prox = NULL;
		return *p;

}

pno eliminaConcorrente(pno p[]){
	pno temp;
	pno aux = *p;
	pno anterior = NULL;

	while( aux != NULL){
		if(aux->id == 123){
			temp = aux->prox;
			free(aux);
			aux = temp;
			anterior->prox = aux;
		}
		anterior = aux;
		aux = aux->prox;
	}	
	temp = aux;
	return *p;

}
