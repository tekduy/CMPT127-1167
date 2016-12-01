#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <draw.h>
#include "imgops.h"

double dist( double x1, double y1, double x2, double y2 )
{
  return( hypot( y2-y1, x2-x1 ));
}

void draw_circle( uint8_t array[],
		  unsigned int cols,
		  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color )
{
  if( r == 0 ){
    return;
  }

  double hor;
  double vert;

  for( hor = fmax(0,x-r); hor < fmin(x+r+1,cols); hor++ ){
    for( vert = fmax(0,y-r); vert< fmin(y+r+1,rows); vert++ ){
      	if( dist( hor, vert, x+0.5, y+0.5 ) < r || dist( hor+1, vert, x+0.5, y+0.5 ) < r ||
      	    dist( hor+1, vert+1, x+0.5, y+0.5 ) < r || dist( hor, vert+1, x+0.5, y+0.5 ) < r){
      	       set_pixel( array, cols, rows, hor, vert, color );
             }
    }
  }
}
