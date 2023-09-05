#include <stdio.h>c
int main()
{
    int a=0, c=0, g=0, t=0;
    char v[1000001];
    scanf(":%s",v);

    for(int i=0; i < v[i];i++){
        if(v[i] == 'A' && v[i+1] == 'A')
            a++;
        if(v[i] == 'C' && v[i+1] == 'C')
            c++;
        if(v[i] == 'G' && v[i+1] == 'G')
            g++;
        if(v[i] == 'T' && v[i+1] == 'T')
            t++;
        printf("%c", v[i]);
    }

    printf("\n%d %d %d %d\n", a, c, g, t);

    /*
    if(a > c && a > g && a > t)
        printf("%d", a);
    if(c > a && c > g && g > t)
        printf("%d", c);
    if(g > a && g > c && g > t)
        printf("%d", g);
    if(t > a && t > c && t > g)
        printf("%d", t);
    */

    return 0;
}
