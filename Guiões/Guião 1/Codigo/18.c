
#include <stdio.h>


// Escrever a função

int main(int argc, char** argv) {
    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};    
    int min1=0, max1=0, min2=0, max2=0;

    // Chamar a função para a matriz m1: Preencher os indices min1 e max1

    // Chamar a função para a matriz m2: Preencher os indices min2 e max2

    printf("Matriz m1: (%d, %d)\n", min1, max1);
    printf("Matriz m2: (%d, %d)\n", min2, max2);
    return 0;
}
