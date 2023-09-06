#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

#define max 1000001


int main()
{

    int i=0,count=0, ans;
    char v[max];


    while(i != EOF){
        scanf("%c", &v[i]);
        i++;
    }

    for(int i=0; i != EOF; i++){
        if(v[i] == v[i+1]){
            count++;
        }
        else
            ans = count;
    }

    printf("%d", ans);


    return 0;
}
