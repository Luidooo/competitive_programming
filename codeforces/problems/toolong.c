#include <stdio.h>

int main(){

    int loops;
    scanf("%d", &loops);
    for(int i=0;i < loops; i++){
        char string[110];
        scanf("%s", string);
        //if(string[10] != 0){
        int w=0;
        while(string[w] != '\0') w++;
        //printf("N vale = %i", w);
        if(w>10) printf("%c%i%c\n", string[0], w-2, string[w-1]);
       // }
        else
            printf("%s\n", string);
    }
}
