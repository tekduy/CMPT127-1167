#include <stdlib.h>
#include <stdio.h>

int i;

int identical( int a[], int b[], unsigned int len )
  {
    for (i = 0; i < len; i++)
      {
        if (a[i] < b[i])
          {
            return 0;
          }
        else if (a[i] > b[i])
          {
            return 0;
          }
      }
      return 1;
  }
