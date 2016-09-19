#include <stdio.h>
int main(void){
    int i, result, done;
    float small;
    float large;
    float arr[100];
    float sum=0;
    float average;
    int n=-1;

    while(result!=EOF)
    {
    for(i=0; result!=EOF; i++)  /* Stores number entered by user. */
    {
       n+=1;
       result = scanf("%f", &arr[i]);
       sum += arr[i];
       //printf("%f", arr[i]);
    }

    //printf("sum = %f n = %f ", sum, n);

    average = sum/n;

    small = arr[0];
    for(i=0; i<n; i++)
    {
      if(arr[i]<arr[n])
      {
        small = arr[i];
      }
    }
    large = arr[0];
    for(i=0; i<n; i++)
    {
      if(arr[i]>arr[n])
      {
        large = arr[i];
      }
    }
    }
    printf("%.2f %.2f %.2f\n", small, average, large);
    return 0;
}
