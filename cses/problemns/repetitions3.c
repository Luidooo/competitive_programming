#include <stdio.h>
#include <stdlib.h>

#define max 1000001


int compare (const void *x_void, const void *y_void)
    {
        int x = *(int *)x_void;
        int y = *(int *)y_void;
        return x - y;
    }

int main()
{
    int a=1, c=1, g=1, t=1;
    char v[1000001];

    scanf("%s", v);
    for(int i=0; i < v[i];i++){
        if(v[i] == 'A' && v[i+1] == 'A')
            a++;
        if(v[i] == 'C' && v[i+1] == 'C')
            c++;
        if(v[i] == 'G' && v[i+1] == 'G')
            g++;
        if(v[i] == 'T' && v[i+1] == 'T')
            t++;
    }

    int d[] = {a, c, g, t};
    int lenght = 4;

    qsort(d,lenght,sizeof(int), compare);

//    for(int i=0;i < 4;i++)
//      printf("%d", d[i]);

    printf("%d\n", d[3]);

    return 0;
}
