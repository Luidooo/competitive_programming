#include <stdlib.h>  
#include <stdio.h>  
#include <math.h>

//se o numero possui duas partes que sao divisiveis por dois

int main()
{
  int n=0,w,i;
  
  scanf("%d", &w);
  
  for(i=1;i<w;i++){
    if((w/i)%2 == 0)
      n++; 
    }

  if(n>2)
    printf("YES");
  else
    printf("NO");

  return 0;
}
