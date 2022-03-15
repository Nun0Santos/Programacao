
#include <stdio.h>
#include <string.h>

#define N	5


void escreve_sin(char *sin[][2], int tot_lin)
{
	printf("Falta implementar funcao\n");
}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{
	printf("Falta implementar funcao\n");
	return NULL;
}


int main()
{
	char palavra[50], *p;
	
	char *s[N][2] = {{"estranho", "bizarro"},
					 {"desconfiar", "suspeitar"},
					 {"vermelho", "encarnado"},
					 {"duvidar", "desconfiar"},
					 {"carro", "automovel"}};	

	
	escreve_sin(s, N);		// alinea 22.1
	
	printf("Palavra a pesquisar: ");
	scanf(" %s", palavra);
	
	p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2
	
	if(p == NULL)
		printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
	else
		printf("A palavra %s e sinonimo de %s\n", p, palavra);
	
	
	// Escrever e testar as restantes funções
	
	
	return 0;
}