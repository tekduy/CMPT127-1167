#include <stdio.h>
#include <math.h>

int main( void )
{
  int a = 0;
  float i = 0;
  int b = 0;

  scanf( "%f", &i );
if (a<i>a)
{
  int x = floor(i);
  int y = round(i);
  int z = ceil(i);

  printf("%d %d %d\n", x, y, z );
  return 0;
}
else
{
  int b = i;
  printf("scanf error: (%d)\n", b );
}
}
