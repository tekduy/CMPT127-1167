

#include <stdio.h>
#include <math.h>

int main( void )
{
int a = 0;
float i = 0;
int b = 0;

int result = 0;

while ( result != EOF)
{
int result = scanf( "%f", &i );

if (result == EOF)
{

    printf("Done.\n");


    return 0;

}

 

if ( result != a )

{

 


    int x = floor(i);


    int y = round(i);


    int z = ceil(i);

 


    printf("%d %d %d\n", x, y, z );

 

}

 

else

{


    if (result == a)

{


      int result = printf("scanf error: (%d)\n", b);


      return 0;

}

}

}

} 
