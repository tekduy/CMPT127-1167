#include <stdlib.h>
#include <stdio.h>

int i = 0;
int fix;

void reverse( int arr[], unsigned int len )
{
  int a[len];
  fix = len - 1;

  for (i=0 ; i<len ; i++)
    {
      a[i] = arr[fix-i];
    }
  for (i=0 ; i<len ; i++)
    {
      arr[i] = a[i];
    }
}
