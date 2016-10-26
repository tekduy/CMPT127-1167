/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[],
           unsigned int cols,
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[],
        unsigned int cols,
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
}

// Set every pixel to 0 (black)
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
  memset(array, 0, cols*rows*sizeof(uint8_t));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[],
           unsigned int cols,
           unsigned int rows )
{
  // your code here
  uint8_t* ret = malloc(cols*rows*sizeof(uint8_t));
  if (!ret) {
     perror("Call to malloc failed\n");
     exit(1);
  }
  memcpy(ret, array, cols*rows*sizeof(uint8_t));
  return ret;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[],
	     unsigned int cols,
	     unsigned int rows )
{
  // your code here
	int dark = array[0];
	int i, k;

	for (i=0; i<cols; i++)
	{
		for(k=0; k<rows; k++)
		{
			if(array[i + k*cols] < dark)
			{
			dark = array[i + k*cols];
			}
		}
	}
  return dark;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[],
		 unsigned int cols,
		 unsigned int rows )
{
  // your code here
	int light = array[0];
	int i, k;

	for(i=0; i<cols; i++)
	{
		for(k=0; k<rows; k++)
		{
			if (array[i + k*cols] > light)
			{
				light = array[i + k*cols];
			}
		}
	}
  return light;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[],
		     unsigned int cols,
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here
  int i, k;
  for (i=0; i<cols; i++){
    for (k=0; k<rows; k++){
      if (array[i+k*cols] == pre_color){
        array[i+k*cols] = post_color;
      }
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[],
              unsigned int cols,
              unsigned int rows )
{
  // your code here
    if (cols*rows == 0)
        return;

    int i, k, temp;

    for (i=0; i<cols/2; i++)
   {
        for (k=0; k<rows; k++)
	{
            temp = array[i + k*cols];
            array[i + k*cols] = array[(cols-1)-i + k*cols];
            array[(cols-1)-i + k*cols] = temp;
        }
    }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
    // your code here
    if (cols*rows == 0)
        return;

    int i, k, temp;

    for (i=0; i<cols; i++)
  {
        for (k=0; k<rows/2; k++)
	{
            temp = array[i + k*cols];
            array[i + k*cols] = array[i + ((rows-1)-k)*cols];
            array[i + ((rows-1)-k)*cols] = temp;
        }
    }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[],
		   unsigned int cols,
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
    int i, k;

    for (i=0; i<rows; i++)
   {
        for (k=0; k<cols; k++)
	{
            if (array[k + i*cols] == color)
	    {
                *x = k;
                *y = i;

                return 1;
            }
        }
    }
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade.
void invert( uint8_t array[],
         unsigned int cols,
         unsigned int rows )
{
    // your code here
    int i, k;
    uint8_t a;

  	for(i=0; i<cols; i++)
  	{
  		for(k=0; k<rows; k++)
  		{
  			a = get_pixel(array, cols, rows, i, k);
        set_pixel(array, cols, rows, i, k, 255-a);
  		}
  	}
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
  int i, k;

  for(i=0; i<cols; i++)
  {
    for(k=0; k<rows; k++)
    {
      if((scale_factor*array[i+k*cols] + 0.5) > 255)
      {
        array[i+k*cols]=255;
      }
      else
      {
        array[i+k*cols]=scale_factor*array[i+k*cols]+0.5;
      }
    }
  }
}

/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max().
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    int minval = min(array, cols, rows) ;
    int maxval = max(array, cols, rows) ;
    double scale_factor = ((maxval - minval) / 255) ;
    double b = ( - (scale_factor * minval) ) ;
    int length = rows * cols ;
  int i ;
  for(i=0;i<length;i++)
  {
    if(array[i] == minval)
      {
        array[i] = 0;
      }
    else if (array[i] == maxval)
    {
      array[i] = 255;
    }
    else
    {
      temp = (round((array[i] * scale_factor)));
      array[i] = (round((array[i] * temp)));
    }
  }
return ;

}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image
// has an odd number of columns, ignore its rightmost column. If the
// original image has an odd number of rows, ignore its bottom row.
// The value of a pixel at (p,q) in the new image is the average of
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in
// the original image.
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
 // your  code here

 int c, r;
 int mean  ;

 int newlength = (cols / 2) * (rows / 2) ;

 uint8_t* newar = malloc((newlength) *sizeof(uint8_t)) ;

   for(c=0;c < (rows - 1); c = c + 2)
   {

     for(r=0; r < (cols - 1) ; r = r + 2 )
     {

       mean = round( ( array[(r) + (c) * cols ] + array[(r + 1) + (c) * cols ] + array[(r) + (c + 1) * cols ] + array[(r + 1) + (c + 1) * cols ] ) / 4.0 ) ;
       newar[(r/2) + (c/2) * (cols/2)] = mean ;

     }

   }

 return newar;
}



/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.

  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.

  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[],
         unsigned int cols,
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
    // your code here
    if ((right-left)*(bottom-top) == 0)
  	{
  		return;
  	}

  	int a, b;
  	for (a=left; a<right; a++)
  	{
  		for(b=top; b<bottom; b++)
  		{
  			array[a+b*cols] = color;
  		}
  	}
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[],
                    unsigned int cols,
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    // your code here
	unsigned long int total = 0;
	int a, b;

	if ((right-left)*(bottom-top) == 0)
	{
		return total;
	}
	for (a=left; a<right; a++)
	{
		for (b=top; b<bottom; b++)
		{
			total = total + array[a + b*cols];
		}
	}

	printf("%lu\n", total);

	return total;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[],
              unsigned int cols,
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
	if ((right-left)*(bottom-top) == 0)
	{
		return NULL;
	}

	uint8_t* copy = malloc((right-left)*(bottom-top)*sizeof(uint8_t));

	if (!copy)
	{
		return NULL;
	}

		int a, b;

	for (a=left; a<right; a++)
	{
		for (b=top; b<bottom; b++)
		{
			copy[(a-left) + (b-top)*(right-left)] = array[a + b*cols];
		}
	}

	return copy;
}
