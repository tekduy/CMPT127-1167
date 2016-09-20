#include <stdio.h>
#include <ctype.h>

int main(void){
    int i, result;
    int arr[100];
    int n = -1;
    char a[] = "#";
    char * ptr = a;

    for(i=0; result!=EOF; i++)
    {
       n+=1;
       result = scanf("%d", &arr[i]);
       //printf("We are at array: %d\n", i);
       //printf("%f\n", arr[i]);
    }
    for(i=0; i<n; i++)
    {
      while(arr[i]-->0)
      {
       printf("%s", ptr);
      }
      printf("\n");
    }

}
