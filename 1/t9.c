#include <stdio.h>
#include <math.h>

int main()
{
  int x, y, z;
  int row, column;

  scanf("%d %d %d", &x, &y, &z);

  for(row = z-1; row >= 0; row--)
    {
      int left = floor ( row * ( x/(2.0*z) ) );
      int right = ceil ( (x-1) + -row * ( x/(2.0*z) ) );

      for(column = 0; column < x ; column++)
        {
          if(column < left)
            {
              printf(" ");
            }
          else if(column == left || column == right)
            {
              printf("#");
            }
          else if (row==0)
            {
              printf("#");
            }
          else if (column > left && column < right && row == z-1)
            {
              printf("#");
            }
          else if ( column > left && column < right)
           {
              printf(".");
           }
          if(column == right)
            {
              printf("\n");
            }
        }
    }
    return 0;
}
