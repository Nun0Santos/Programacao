
#include <stdio.h>

#define L1	3
#define C1	2

#define L2	4
#define C2	3


void escreve(int n_lin, int n_col, ...)
{
	//printf("Falta implementar funcao\n");
}


int main()
{

	int mat1[L1][C1] = {{1,2}, {3,4}, {5,6}};
	
	int mat2[L2][C2] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
	
	
	printf("Matriz 1:\n");
	escreve(L1, C1, ...);
	
	printf("Matriz 2:\n");
	escreve(L2, C2, ...);
	
	return 0;
}