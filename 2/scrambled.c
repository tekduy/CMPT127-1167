#include <stdlib.h>
#include <stdio.h>

int i, fix;

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
  fix = len - 1;
  for ( i = 0 ; i < len ; i++ )
    {
      if (a[i] == b[i])
        {
          return 1;
        }
      if (a[i] == b[fix-i])
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
}
