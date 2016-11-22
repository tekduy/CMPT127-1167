#include <stdio.h>
#include <math.h>

int main(void)
{
  int arr[100];
  int i,k;
  int result, temp;
  int len = -1;
  int maxheight = 0;

  for (i=0; result!=EOF; i++)
  {
    result = scanf("%d", &arr[i]);
    len++;
  }
  temp = arr[0];
  for (i=0; i<len; i++)
  {
    if (temp < arr[i])
    {
      temp = arr[i];
    }
    maxheight = temp;
  }
  for (i=1; i<=maxheight; i++){
    for (k=0; k<len; k++){
      if (arr[k] == maxheight ){
        printf("#");
      }
      else if (arr[k] == (maxheight-i+1)){
        arr[k] = arr[k]-1;
        printf("#");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
