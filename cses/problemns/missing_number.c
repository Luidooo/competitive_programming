#include <stdio.h>
#include <math.h>


int main()
{
    int n, t, w = 0, soma = 0, valor = 0;
    scanf("%d", &n);
    for(int i; i < n-1 ;i++){
        scanf("%d",&t);
        w = w + t;

    }

    for(int i=0;i<=n;i++){
        valor += i;
    }

    printf(" %d", valor-w);


    return 0;
}
