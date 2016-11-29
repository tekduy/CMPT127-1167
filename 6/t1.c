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

assert(ia);
assert(ia->data);

FILE* f = fopen("filename", "w");
if (f == NULL){
  puts ("Failed to open image file for writing");
	return 1; //Unable to open file
}

//Write
unsigned int len = ia->len;
intarr_t * arr = intarr_create(len);
arr->len = ia->len;
arr->data = ia->data;

fwrite(arr, sizeof(intarr_t), len, f);
fclose(f);

return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){
  unsigned int len;
	FILE * f = fopen("filename", "r");
	if (f == NULL){
		return 1; //Unable to open file
	}

  fseek(f, 0, SEEK_END);
  len = ftell(f);
  fseek(f, 0, SEEK_SET);
  intarr_t * newia = intarr_create(len);
  fread(newia, sizeof(intarr_t), len, f);
	fclose(f);
	return newia;
}
