#include <stdio.h>
#include <math.h>

int main()
{
    char n;
    int a=0, c=0, g=0, t=0;
    while(scanf("%c",&n)==1){
        scanf("%c",&n);
        if(n == 'a')
            a++;
        if(n == 'c')
            c++;

        if(n == 'g')
            g++;

        if(n == 't')
            t++;
    }

    if(a > c)
        printf("%d",a);






    return 0;
}
