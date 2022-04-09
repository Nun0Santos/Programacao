#include <stdio.h>
#include <stdlib.h>


int comuns();
void inicializa();
void mostra();

int main(){
    int dimA=6,dimB=9, *tabA = NULL, *tabB = NULL;
    const int a[6] = {1, 3, 2, 6, 5, 4};
    const int b[9] = {9, 5, 3, 3, 1, 4, 8, 7, 23};
    
    tabA = malloc(sizeof(int) * dimA);
    if(tabA == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

    
    tabB = malloc(sizeof(int) * dimB);
    if(tabB == NULL){
        printf("Erro na alocação de memória");
        return 0;
    }

   printf("%d\n",comuns(a,dimA,b,dimB));
}

int comuns(const int *vA, int tamA, const int *vB, int tamB){
    int count =0, numeros[4], num;

    for(int i=0; i<tamA; ++i){
        for(int j=0; j<tamB; ++j){
            if(vA[i] == vB[j]){
                numeros[i] = vA[i];
                num = vA[i];
                ++count;
                for(int x =j+1;  x<tamB; ++x){
                    if(num == vB[x]){
                        --count;
                    }
                }
            } 
        }    
    }
    return count;
}