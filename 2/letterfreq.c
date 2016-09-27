#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main (int argc, char * argv[])
  {
    char alpha[26] = "abcdefghijklmnopqrstuvwxyz";
    float freq[26];
    int a;
    int count = 0;
    int i;

    for (i=0; i<26; i++)
      {
        freq[i] = 0.0;
      }

    while (a != EOF)
      {
        a = getchar();

        for (i=0; i<26; i++)
          {
            if (a == alpha[i])
              {
                freq[i]++;
                count++;
                break;
              }
          }

        if (isupper(a))
          {
            a = tolower(a);
            for (i=0; i<26; i++)
              {
                if (a == alpha[i])
                  {
                    freq[i]++;
                    count++;
                    break;
                  }
              }
          }
      }
    for (i=0; i<26; i++)
      {
        if (freq[i] !=0)
          {
            printf("%c %.4f\n", alpha[i], freq[i]/count);
          }
      }

  }
