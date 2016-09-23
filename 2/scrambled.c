#include <stdio.h>

int scrambled (unsigned int a[], unsigned int b[], unsigned int len)
{

  if (len == 0)
    {
      return 1;
    }

  int c[len], d[len];
  int j;

  for (j=0;j<len;j++)
    {
      c[j] = a[j];
      d[j] = b[j];
    }

  int i, k;

  for (i=0;i<len;i++)
    {
      int mina = c[i];
      int minapos = i;

        for (k=i;k<len;k++)
          {
            if (c[k] < mina)
              {
                mina = c[k];
                minapos = k;
              }
          }
      c[minapos] = c[i];
      c[i] = mina;
    }

    for (i=0;i<len;i++)
      {
        int minb = d[i];
        int minbpos = i;

          for (k=i;k<len;k++)
            {
              if (d[k] < minb)
                {
                  minb = d[k];
                  minbpos = k;
                }
            }
        d[minbpos] = d[i];
        d[i] = minb;
      }

    int total = 0;

    for (i=0;i<len;i++)
      {
        if (c[i]==d[i])
          {
            total = total + 1;
          }
      }
    if (total == len)
      {
        return 1;
      }
    else
      {
        return 0;
      }
}
