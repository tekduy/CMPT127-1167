#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#include "point_array.h"

/*

typedef struct point
{
  double x, y, z;
} point_t;

typedef struct
{
  // number of points in the array
  size_t len;

  // pointer to an array of point_t structs
  // There is space for 'allocated' structs, but
  // 'len' structs have been used so far.
  point_t* points;

  // to be discussed in class
  size_t reserved;

} point_array_t;

*/

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
  int i = 0;
  assert(pa != NULL);
  pa->len = 0;
  pa->reserved = 0;
  pa->points = NULL;
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
  pa->len = 0;
  free(pa->points);
  pa->points = NULL;
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
  if (pa == NULL){
    return 1;
  }
  pa->len = pa-> len + 1 ;
  pa->points = realloc(pa->points, pa->len * sizeof(point_t));
  if (pa->points == NULL){
    return 1;
  }
  pa->points[pa->len - 1].x = p->x ;
	pa->points[pa->len - 1].y = p->y ;
	pa->points[pa->len - 1].z = p->z ;
	return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
  if ( pa == NULL ){
	return 1;
  }

  if (i >= pa->len){
     return 1;
  }

  if( pa->len == 0){
	return 1;
  }
  int len2 = pa->len;
  int j = i ;
  //int k;
  //int len2 = pa->len;

	pa->points[j].x = pa->points[len2-1].x ;
	pa->points[j].y = pa->points[len2-1].y ;
	pa->points[j].z = pa->points[len2-1].z ;

	pa->points = realloc(pa->points, (pa->len-1) * sizeof(point_t)) ;
	if(pa->points == NULL)
	{
		return 1 ;
	}
	pa->len = (pa->len)-1;
	return 0;
}
