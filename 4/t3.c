#include <stdint.h>
#include <stdlib.h>

#include "imgops.h"

unsigned int hoodsize( uint8_t array[], unsigned int cols, unsigned int rows, unsigned int p, unsigned int q ){
	int i = p;
	int j = q;
	int c, d;
	int aa, bb;

	unsigned int total = 0;

	for( c=-1; c<=1; c++ ){
		for( d=-1; d<=1; d++ ){
			if( !(c == 0 && d == 0) ){
				aa = (i+c+cols) % cols;
				bb = (j+d+rows) % rows;
				total += get_pixel( array, cols, rows, aa, bb ) > 0;
			}
		}
	}
	return total;
}


void life( uint8_t array[], unsigned int cols, unsigned int rows ){

	uint8_t* cop = copy( array, cols, rows );
	int a, b;

	for( a=0; a<cols; a++ ){
		for( b=0; b<rows; b++ ){
			unsigned int hoody = hoodsize( cp, cols, rows, a, b );

			if( hoody < 2 ){
				set_pixel( array, cols, rows, a, b, 0 );
			}
      if( hoody == 3 ){
        set_pixel( array, cols, rows, a, b, 255 );
      }
			if( hoody > 3 ){
				set_pixel( array, cols, rows, a, b, 0 );
			}
		}
	}

	free(cop);
}
