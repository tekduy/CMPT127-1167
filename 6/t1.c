#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "intarr.h"



/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){

const size_t len = ia->len;
int arr[len];

intarr_t* arr = malloc(sizeof(intarr_t));

if( arr == 0 )
{
	printf( "Failed to allocate memory for intarr\n" );
	return -1;
}

arr->data = malloc(len * sizeof(int));
assert (arr->data != NULL);
arr->len = len;

if (ia == NULL){
	return INTARR_BADARRAY;
}
if(ia != NULL){
	arr->data = ia->data;
}
else{
	return INTARR_BADINDEX;
}

FILE* f = fopen("filename", "w");
fwrite(arr, sizeof(int), len, f);
fclose(f);

return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){
	const size_t len = 0;
	FILE* f = fopen("filename", "r");
	fscanf (f, "%d", len);
	intarr_t * newia = malloc(sizeof(intarr_t));
	assert (newia);
	newia->data = malloc(len*sizeof(int));
	assert(newia->data);
	newia->len = len;
	if (f != NULL){
		while(!feof(f)){
			fscanf(f, "%d", newia->data);
		}
	}
	else{
		return NULL;
	}
	fclose(f);
	return newia;
}

