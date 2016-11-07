#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "intarr.h"

/*
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 *
 */

/* DO NOT CHANGE THIS FILE - YOUR CODE WILL BE COMPILED AGAINST THE
   ORIGINAL. NON-COMPILING CODE WILL FAIL ALL THE TASKS!

   FOR TASKS WITH MORE THAN ONE FUNCTION, YOU MUST IMPLEMENT ALL
   FUNCTIONS TO PASS THE TASK.
*/

/* Structure type that encapsulates our safe int array. */

/*
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;
*/

/* A type for returning status codes */
/*
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;
*/

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
  intarr_t* arr = malloc( sizeof(intarr_t));

	if( arr == 0 )
	{
		printf( "Failed to allocate memory for intarr\n" );
		return NULL;
	}

	arr->data = malloc( len * sizeof(int));
	assert (arr->data != NULL);
	arr->len = len;
	return arr;
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
  if (ia == NULL)
	{
		printf( "Pointer was NULL, exiting intarr_destroy");
		return;
	}
	if (ia->data == NULL)
	{
		printf( "ia data was NULL, exiting intarr_destroy");
		free(ia);
		return;
	}

	free(ia->data);
	free(ia);
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia,
			    unsigned int index,
			    int val ){
            if (ia == NULL)
            {
              return INTARR_BADARRAY;
            }
            if (index < (ia->len))
            {
              ia->data[index] = val;
              return INTARR_OK;
            }
            else
            {
              return INTARR_BADINDEX;
            }
          }

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
			    unsigned int index,
			    int* i ){
            if (ia == NULL)
            {
              return INTARR_BADARRAY;
            }
            if (i != NULL && index < (ia->len))
            {
              *i = ia->data[index];
              return INTARR_OK;
            }
            else
            {
              return INTARR_BADINDEX;
            }
          }

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ){
  if (ia == NULL)
  {
    return NULL;
  }

  unsigned int numbytes = ia->len * sizeof(int);
  intarr_t* ia_copy = malloc(sizeof(intarr_t));

  if( ia_copy == 0 )
  {
    printf( "Failed to allocate memory for ia copy\n" );
    return NULL;
  }

  ia_copy->data = malloc(numbytes);

  if (ia_copy->data == NULL)
  {
    printf( "Failed to allocate memory for ia copy->data\n" );
    return NULL;
  }

  ia_copy->len = ia->len;
  memcpy(ia_copy->data, ia->data, numbytes);
  return ia_copy;
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }

  int i , j , temp;
  for (i=0; i < ((ia->len)-1); i++)
  {
    for (j=0; j < ((ia->len) - i - 1); j++)
    {
      if (ia->data[j] > ia->data[j+1])
      {
        temp = ia->data[j+1];
        ia->data[j+1] = ia->data[j];
        ia->data[j] = temp;
      }
    }
  }

  return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }
  for (int k=0; k < ia->len; k++)
  {
    if (ia->data[k] == target && i != NULL)
    {
      *i = k;
      return INTARR_OK;
    }
  }

  return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }
  ia->data = realloc(ia->data, (ia->len+1)*sizeof(int));
  if (ia->data == NULL)
  {
    return INTARR_BADALLOC;
  }

  ia->len = (ia->len)+1;
  ia->data[(ia->len)-1] = val;
  return INTARR_OK;
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }
  if (ia->len == 0)
  {
    return INTARR_BADINDEX;
  }
  if ( i != NULL)
  {
    *i = ia->data[ia->len-1];
  }

  ia->data = realloc(ia->data, (ia->len-1)*sizeof(int));
  ia->len = (ia->len)-1;
  return INTARR_OK;
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  unsigned int oldlen = ia->len;

  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }

  ia->data = realloc(ia->data, newlen * sizeof(int));

  if (ia->data == NULL)
  {
    return INTARR_BADALLOC;
  }
  if ( newlen > oldlen )
  {
    for (int i = oldlen-1; i < newlen-1; i++)
    {
      ia->data[i] = 0;
    }
  }

  ia->len = newlen;
  return INTARR_OK;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia,
				unsigned int first,
				unsigned int last ){
          unsigned int arrlen = ia->len;
          unsigned int newlen = last-first+1;

          if (ia == NULL || last < first || first > arrlen || last > arrlen )
          {
            return NULL;
          }
          intarr_t* copy = malloc(sizeof(intarr_t));
          if (copy == NULL)
          {
            return NULL;
          }
          copy->data = malloc(newlen * sizeof(int));
          if (copy->data == NULL)
          {
            return NULL;
          }

          memcpy (copy->data, ia->data + first, newlen * sizeof(int));
          copy->len = newlen;
          return copy;
        }
