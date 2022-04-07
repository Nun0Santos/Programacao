#include "utils.h"
#define MAX 10 

int main(){
    retangulo r[MAX];
    int total = 0;

    for(int i=0;i<4;++i){
        G2Ex3b(r,&total);
    }

    puts("\n");
    G2Ex3c(r,total);
    printf("Total: %d\n",total);

    puts("\n");
    //printf("%d\n",G2Ex3d(r,&total));
    
    printf("Eliminados = %d\n",G2Ex3e(r,&total,20));
    printf("=======================================\n");
    printf("\nDepois de eliminar :\n");

    G2Ex3c(r,total);
    printf("Total: %d\n",total);



    return 0;
}