#include <stdio.h>
#include <ctype.h>

int main(void){
    int i, result, z, x, y;
    int arr[100];
    char a[] = "#";
    char b[] = ".";
    int var0 = 0;
    int var1 = 0;

    for(i=0; i<3; i++)
    {
       result = scanf("%d", &arr[i]);
       //printf("i is: %d\n", i);
    }
    var0 = arr[0] - 2;
    var1 = arr[1] - 2;
      for(y=0; y<arr[0]; y++)
      {
       printf("%s", a);
      }
      printf("\n");

      for(z=0; z<var1; z++)
      {
        printf("%s",a);
        for(i=0; i<var0; i++)
        {
        printf("%s", b);
        }
        printf("%s",a);
        printf("\n");
      //printf("i is: %d\n", i);
      }
      if(arr[0]>1)
      {
      for(x=0; x<arr[0]; x++)
      {
       printf("%s", a);
      }
      printf("\n");
      }
}
