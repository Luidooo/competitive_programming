#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int loops; scanf("%i", &loops);
    int player; int problemns=0,aux=0;
    for(int i=0; i<loops;i++){
        for(int j=0;j<3;j++){
            scanf("%i", &player);
            if(player == 1) aux++;
        }
        if(aux >= 2) problemns++;
        //printf("problemns %d e aux %d\n", problemns, aux);
        aux = 0;
    }

    printf("%i\n", problemns);
}
