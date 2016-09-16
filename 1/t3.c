#include <stdio.h>
#include <math.h>

int main( void )
{
  float i = 0;

  scanf( "%f", &i );
  int x = floor(i);
  int y = round(i);
  int z = ceil(i);

  printf( "%d %d %d\n", x, y, z );

  return 0;
}
