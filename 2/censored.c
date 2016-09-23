#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char arr[128];
	memset(arr, 0, 50);
	int result, i=0;
	int count;

	while ((result=getchar()) != EOF)
		{
			if (isalnum(result) || result == 39)
			{
				arr[i] = result;
				i+=1;
			}
			else
				{
					for (count = 0; count < argc; count++)
						{
							if (strcmp(arr, argv[count]) == 0)
								{
									printf("CENSORED");
									memset(arr, 0, 128);
									i = 0;
								}
						}
					if (strlen(arr) != 0)
						{
							printf("%s", arr);
							memset(arr, 0, 128);
							i=0;
						}
					putchar(result);
				}
		}
	return 0;
}
