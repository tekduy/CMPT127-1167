#include <stdio.h>
#include <ctype.h>

int main(void){
    int i, result;
    float small;
    float large;
    float arr[100];
    float sum=0;
    float average;
    int n=-1;

    for(i=0; result!=EOF; i++)  /* Stores number entered by user. */
    {
       n+=1;
       result = scanf("%f", &arr[i]);
       sum += arr[i];
       //printf("%f", arr[i]);
       if (isalpha(arr[i]))
       {
       n-=1;
       }
    }

    //printf("sum = %f n = %f ", sum, n);

    average = sum/n;

    small = arr[0];
    for(i=0; i<n; i++)
    {
      if(arr[i]<arr[0])
      {
        small = arr[i];
      }
      //printf("Small is: %f\n", small);
    }
    large = arr[0];
    for(i=0; i<n; i++)
    {
      if(arr[i]>arr[0])
      {
        large = arr[i];
      }
    }
    if ( result == EOF )
    {
    printf("%.2f %.2f %.2f\n", small, large, average);
    return 0;
    }
}
