#include <stdlib.h>
#include <stdio.h>

int i, fix, z;
int yes = 0;
int flag1 = 0;

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
  fix = len - 1;
  if (len == 0)
    {
      printf("Loop 1\n");
      return 1;
    }

//  for ( i = 0; i < len; i++)
//    {
//      if (a[i] == b[i])
//        {
//          printf("Loop 2\n");
//          flag1 = 1;
//        }
//      else
//        {
//          flag1 = 0;
//        }
//    }

//    for ( i = 0; i < len; i++)
//      {
//        if (a[i] == b[fix-i])
//          {
//            printf("Loop 3\n");
//            return 1;
//          }
//      }

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
if (2 > yes)
{
if (0 < yes)
  {
    printf("Yes\n");
    return 1;
  }
}
  return 0;
}
