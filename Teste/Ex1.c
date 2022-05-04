#include <stdlib.h>
#include <stdio.h>

int funcao();

void main(){
    int array[7] = {1,2,5,4,2,1,2};
    printf("%d\n",funcao(array,7));
}

int funcao(int*  a, int tam){
    int i, soma = 0  , *p = a ;

    for(i=0; i<tam; i++, p++  )
        if ((*p - *a   != 0) && p[0]   != *(a+tam-1))
            soma += *p;
    return soma;
}