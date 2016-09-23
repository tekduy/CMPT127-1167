#include <stdio.h>
#include <string.h>

int main (void)
{
  int i;
  char result;
  unsigned long charcount = 0, wordcount = 0, linecount = 0, start = 0;

  while ((result = getchar()) != EOF)
    {
      charcount+=1;

      if (result == '\n')
        {
          linecount+=1;
        }
      if(start == 0 )
        {
        	if(   (result == 39) || ((65 <= result) && (result<= 90)) || ((97 <= result) && (result <= 122))   )
            {
        		  start = 1;
        		  wordcount+=1;
        		}
        }
      else if( result != 39  )
        {
        	if( (result < 65) || (result > 122) || ((90 < result) &&  (result < 97))  )
        		{
        		  start = 0;
        		}
        }
    }
  printf("%lu %lu %lu\n", charcount, wordcount, linecount);
  return 0;
}
