#include <stdio.h>
#include <math.h>

int main()
{
  int w;
  scanf(" %d", &w);

  if(w>=2 || w%2 ==0)
   printf("YES");
  else
   printf("NO");
  return 0;
}
