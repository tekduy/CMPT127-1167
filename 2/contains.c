#include <stdio.h>
#include <string.h>

int main( int argc, char * argv[])
{
  int a,b;

  a = strlen(argv[1]);
  b = strlen(argv[2]);

  int right = 0;
  int i, j;

  for (i=0; i<a; i++)
    {
        if(argv[1][i] == argv[2][0])
          {
            right = 1;

            for (j=0;j<b;j++)
              {
                if (argv[1][i+j] != argv[2][j])
                  {
                    right = 0;
                    break;
                  }
              }
          }
    }
  if (right == 1)
    {
      printf("true\n");
      return 0;
    }
  if (right == 0)
    {
      printf("false\n");
      return 0;
    }
}

