#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
void G0Ex9();
int validaCond();
int G0Ex10();
void G0Ex11();
void G0Ex12();
void G0Ex13();
void G0Ex15();

int main(){
  
    int tab[TAM] = {1,-2,10,9,8,2,9,4,-4,10};
    int tab1[TAM1] = {1,4,5,2,8};
    int tab2[6] = {1,-2,3,4,-5,6};
    int mat[N][3];
    int mat1[N][3] = {{1,4,5},
                     {6,9,3}};

    int mat2[3][3] = {{6,1,8},
                     {7,5,3},
                     {2,9,4}}; 
    
    char string1[30] = {"Hoje é Domingo!"};
    char string2[30] = {"Hoje   é   Domingo!"};
    char string[30];
    //printf("Maior elemento: %d\n",G0Ex1(tab,TAM));
    //printf("O maior valor surgio na posicao: %d\n",G0Ex2(tab,TAM));
    //printf("O maior elemento surge %d vezes\n",G0Ex3(tab,TAM));
    //printf("O numero que se repete mais vezes e : %d\n",G0Ex4(tab,TAM));
    //printf("Return: %d\n",G0Ex5(tab,TAM,20));
    //G0Ex6(tab2,6,8);
    //G0Ex8(mat,3);
    // G0Ex9(mat1,2);
    //printf("%d\n",G0Ex10(mat2));
    G0Ex11("Hoje e Domingo!");
    //G0Ex12(string1);
    //G0Ex13(string1, string2, string);
    G0Ex15(string1);
    return 0;
}

int G0Ex1(int tabela[], int tam){
    int maior=tabela[0]; // Dizer sempre que o maior é igual ao primeiro elemento
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
        }
    }
    return pos;
}

int G0Ex3(int tabela[], int tam){
    int contador=0,maior=tabela[0];
    maior = G0Ex1(tabela,tam); //Retorna o maior elemento
    for(int i=0; i<tam; ++i){
        if(maior == tabela[i]){
            ++contador;
        }
    }
    return contador;
}

int G0Ex4(int tabela[], int tam){
    int nRep=0,contador; 
    int num =0,maxConta=0;
    
    for(int i=0; i<tam; ++i){
        contador = 1;
        for(int j=i+1; j<tam; ++j){
            if(tabela[i] == tabela[j]){
                ++contador;       
            }
        }
        if(contador > maxConta || contador == maxConta && tabela[i] > nRep){
                maxConta = contador;
                nRep = tabela[i];
        }
    }
    return nRep;
}

int G0Ex5(int tabela[], int tam, int num){
    int aux=0,troca=0;
    for(int i=0; i<tam-1; ++i){
        troca=0;
        for(int j=0; j<tam-i-1; ++j){
            if(tabela[j] > tabela[j+1]){
                aux = tabela[j];
                tabela[j]=tabela[j+1];
                tabela[j+1]=aux;
                troca=1;
            }
        }
        if(troca==0)
            break;  
    }
    printArray(tabela,tam);
    for(int i=0; i<tam && tabela[i] <= num; ++i){
        if(tabela[i] == num)
            return 1;
    }
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
        exit(0);
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

void G0Ex8(int matriz[][3], int nLinhas){
    int num;
    for(int i=0; i<nLinhas; ++i){ //linhas
        for(int j=0; j<3; ++j){ //colunas
            if(j==0){
                do{ 
                    printf("Número = ");
                    scanf("%d",&num);
                }while(validaCond(num,matriz,i) == 0); 
                matriz[i][j] = num;
            } 
            else{ // Entra aqui sempre que o j != 0
                matriz[i][j] = pow(matriz[i][0],j+1);
            }
        }
    }
    G0Ex9(matriz,3);
}
int validaCond(int v, int a[][3], int lin){ //lin-> LInha a preencher se entrar a linha 4 tem de ir verificar a 0 1 2 3
    int i;

    if(v < 1 || v > 100)
        return 0;
    for(i = 0; i<lin; ++i){
        if(a[i][0] == v)
            return 0;
    }
    return 1;
}

void G0Ex9(int matriz[][3], int nLinhas){
    for(int i=0; i<nLinhas; ++i){
        for(int j=0; j<3; ++j){
            printf("%d\t",matriz[i][j]);
        }
        putchar('\n');
    }
}

int G0Ex10(int mat[3][3]){ // falta a diagonal secundaria
    int linha1,linha2,linha3,coluna1,coluna2,coluna3,dig1,dig2;
    int somaL1=0, somaL2=0, somaL3=0, somaC1=0, somaC2=0, somaC3=0, somaDig1=0,somaDig2=0;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(i==0){
                somaL1 += mat[i][j];
            }
            if(i == 1){
                somaL2 += mat[i][j];
            }
             if(i == 2){
                somaL3 += mat[i][j];
            } 
            if(j == 0){
                somaC1+= mat[i][j];
            }
             if(j == 1){
                somaC2 += mat[i][j];
            }
             if(j == 2){
                somaC3 += mat[i][j];
            }
             if(i == j){ //Dig Principal
                somaDig1 += mat[i][j];
            }
             /*if(j == 1 ){ //DIg Secundária (a linha cresce a coluna decresce)
                somaDig2 += mat[i][j];
                printf("%d",somaDig2);
            }*/
            if(somaL1 == somaL2 == somaL3 == somaC1 == somaC2 == somaC3 == somaDig1){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

void G0Ex11(char str[]){
    char strInvertida[30]; 
    int i,j=0;
    i = strlen(str)-1;

    for(i; i>=0; --i){
        strInvertida[j] = str[i];
        ++j;;
    }

    printf("String invertida : %s\n",str);
}

void G0Ex12(char str[]){
    int tam = strlen(str)-1;

    for(int i=0; i<=tam; ++i){
        if(str[i] == ' '){
            str[i] = '\n';
        }
    }
    for(int i = 0; i<=tam; ++i){
        printf("%c",str[i]);
    }
}

void G0Ex13(char str1[], char str2[], char str3[]){ //Não está acabada
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int x=0;
    for(int i = 0; i< tam1; ++i){
        for(int j = 0; j<tam2; ++j){
            if(strcmp(str1,str2) == 0 && tam1 == tam2){
                strcpy(str3,"Conteudo Igual!");
            }
            if(strcmp(str1,str2) != 0 && tam1 == tam2){
                strcpy(str3, "Tamanho igual!");
            }
            else{
                if(tam1 > tam2){
                    strcat(str2,str1);
                    strcpy(str3,str2);
                }
                strcat(str1,str2);
                strcpy(str3,str1);
            }
        }
    }
    printf("%s",str3);
}

void G0Ex15(char str[]){
    int j=1;
 
    for(int i = 1; str[i]; ++i){
        if(str[i] != ' ' || str[i - 1] != ' '){
            str[j] = str[i];
            ++j;
        }
    }
    str[j] = '\0';
    printf("%s\n",str);
}