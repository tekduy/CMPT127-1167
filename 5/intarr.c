#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
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

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
  intarr_t* arr = malloc(sizeof(intarr_t));

  if(arr==0)
  {
    return NULL;
  }

  arr->data = malloc(len*sizeof(int));
  assert (arr->data != NULL);
  arr->len = len;
  return arr;
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
  if (ia == NULL){
    return;
  }
  if (ia->data == NULL){
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
			    int val )
{
  if (ia == NULL){
    return INTARR_BADARRAY;
  }
  else if (index > 0 && index < (ia->len)){
    ia->data[index] = val;
    return INTARR_OK;
  }
  else{
    return INTARR_BADINDEX;
  }
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
			    unsigned int index,
			    int* i )
{
  if (ia == NULL){
    return INTARR_BADARRAY;
  }
  else if (index < (ia->len) && i != NULL){
    *i = ia->data[index];
    return INTARR_OK;
  }
  else{
    return INTARR_BADINDEX;
  }
}
