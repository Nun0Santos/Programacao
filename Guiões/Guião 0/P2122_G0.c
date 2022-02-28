#include <stdio.h>
#define TAM 10
#define TAM1 5
#define N 100

int G0Ex1();
int G0Ex2();
int G0Ex3();
int G0Ex4();
int G0Ex5();
void printArray();
void G0Ex6();
void G0Ex8();

int main(){
  
    int tab[TAM] = {1,2,3,9,8,2,3,4,9,7};
    int tab1[TAM1] = {1,4,5,2,8};
    int tab2[6] = {1,-2,3,4,-5,6};
    int mat[N][3];
    /*printf("Maior elemento: %d\n",G0Ex1(tab,TAM));
    printf("O maior valor surgio na posicao: %d\n",G0Ex2(tab,TAM));
    printf("O maior elemento surge %d vezes\n",G0Ex3(tab,TAM));
    printf("O numero que se repete mais vezes e : %d\n",G0Ex4(tab,TAM));*/
    printf("Return: %d\n",G0Ex5(tab1,TAM1,30));*/
    //G0Ex6(tab2,6,8);
    //G0Ex8(mat,2);
    return 0;
}

int G0Ex1(int tabela[], int tam){
    int maior=0;
    for(int i =0; i<tam; ++i){
        if(tabela[i] > maior){
            maior=tabela[i];
        }
       
    }
    return maior;
}

int G0Ex2(int tabela[], int tam){
    int pos=0,maior=0;
    maior=G0Ex1(tabela,tam);
    for(int i=0; i<tam; ++i){
        if(tabela[i] == maior){
            pos=i;
            return pos;
        }
    }
}

int G0Ex3(int tabela[], int tam){
    int contador=0,maior=0;
    maior = G0Ex1(tabela,tam); //Retorna o maior elemento
    for(int i=0; i<tam; ++i){
        if(maior == tabela[i]){
            ++contador;
        }
    }
    return contador;
}

int G0Ex4(int tabela[], int tam){ //Nao esta bem feita
    int nRep=0,contador=0;
    for(int i=0; i<tam; ++i){
        for(int j=i+1; j<tam; ++j){
            if(tabela[i] == tabela[j]){
                nRep=tabela[i];
                ++contador;

            }
        }
    }
    return nRep;
}

int G0Ex5(int tabela[], int tam, int num){ //Duvida bubble sort
    int aux=0,troca=0;
    for(int i=0; i<tam-1; ++i){
        troca=0;
        for(int j=0; j<tam-i-1; ++j){
            if(tabela[i] > tabela[i+1]){
                aux = tabela[i];
                tabela[i]=tabela[i+1];
                tabela[i+1]=aux;
                troca=1;
            }
        }
        if(troca==0)
            break;  
    }
    printArray(tabela,tam);
    return 0;
}

void printArray(int tabela[], int tam){
    for(int i=0; i<tam; ++i){
        printf("Tab1[%d] = %d\n",i,tabela[i]);
        
    }
}

void G0Ex6(int tabela[], int dim, int valor){
    if(dim < 3){
        printf("Dimensao da tabela invalida (>=3)");
    }
    for(int i=0; i<dim; ++i){
        for(int j=i+1; j<dim; ++j){
            for(int x=j+1; x<dim; ++x){
                 if(tabela[i] + tabela[j]  + tabela[x] == valor){
                     printf("%d %d %d\tsoma=%d\n",tabela[i],tabela[j],tabela[x],tabela[i]+tabela[j]+tabela[x]);
            }
            }
        }
    }
    
}

void G0Ex8(char matriz[][3], int nLinhas){
    for(int i=0; i<3; ++i){
        for(int j=0; i<nLinhas; ++j){
            for(int x=0; x<3; ++x){
                if(x==i){
                    printf("Matriz[%d][%d] ",j,x);
                }
            }
        }
    }

}