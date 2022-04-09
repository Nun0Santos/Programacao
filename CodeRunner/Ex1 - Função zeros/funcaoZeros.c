#include <stdio.h>
#define TAM 6

void zeros();
void printVetor();

int main(){
	int a[TAM] = {1,2,0,3,0,4};
	zeros(a,TAM);	
}

void zeros(int v[], int tam){
	int j=0;

	for(int i=0; i<tam; ++i){
		if(v[i] == 0){
			for(j=i; j>0; --j){
				v[j] = v[j-1]; 	
	   		}
			v[j] = 0;
		}   
	}
}

void printVetor(int v[], int tam){
	for(int i=0; i<tam; ++i){
		printf("Vetor[%d] = %d\n",i,v[i]);
	}
	
}
