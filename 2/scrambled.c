#include <stdlib.h>
#include <stdio.h>

int i, fix, z;
int flag = 0;
int yes = 0;

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
  //fix = len - 1;
  //for ( i = 0; i < len; i++)
    //{
      //if (a[i] == b[i])
        //{
        //  return 1;
        //}
  //  }

  //  for ( i = 0; i < len; i++)
    //  {
    //    if (a[i] == b[fix-i])
  //        {
    //        return 1;
    //      }
  //    }

for (z = 0; z < len; z++)
  {
    for (i = 0; i < len; i++)
      {
        if (a[z] == b[i])
          {
            printf("i is: %d.......", i);
            printf("z is: %d.......", z);
            printf("These are the same - a[z] is: %d and b[i] is: %d\n", a[z], b[i]);
            yes+=1;
          }
      }
  }
yes = yes/len;
if (yes == len)
  {
    return 1;
  }
  return 0;
}
