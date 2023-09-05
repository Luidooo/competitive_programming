#include <stdio.h>

int main()
{


    long long n;
    scanf("%lld", &n);
    printf("%lld", n);

    while(n != 1)
        if( n % 2 == 0 ){
            n = n/2;
            printf(" %lld", n);
        }

        else{
            n = n*3 + 1;
            printf(" %lld", n);
        }

    return 0;
}
