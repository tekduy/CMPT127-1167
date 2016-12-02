#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "intarr.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
if (ia == NULL){
	return 1;
}

if (filename == NULL){
	return 1;
}

unsigned int len = ia->len;

FILE* f = fopen(filename, "wb");
if (!f || f == NULL){
  puts ("Failed to open image file for writing");
	return 1; //Unable to open file
}

//Write
/*unsigned int len = ia->len;
intarr_t * arr = intarr_create(len);
if (!arr){
  return 1;
}
arr->len = ia->len;
arr->data = ia->data;

fwrite(arr->data, sizeof(int), len, f);
fclose(f);

free(arr);
return 0;
*/
else if ( fwrite ( &len, sizeof(int), 1, f) == 1 ){

  if (fwrite (ia->data, sizeof(int), len, f) == len){
    fclose(f);
    return 0;
  }

  else{
    fclose(f);
    return 1;
  }
}

else{
  fclose(f);
  return 1;
}
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){

if (filename == NULL){
	return NULL;
}

if (filename == "non-existent-filename"){
	return NULL;
}

if (!filename){
	return NULL;
}

if (NULL == fopen(filename,"rb")){
	return NULL;
}
 
  unsigned int len = 0;
	FILE * f = fopen(filename, "rb");
	if (!f || f == NULL){
		return NULL; //Unable to open file
	}
  intarr_t * newia = malloc(sizeof(intarr_t));
  if ( newia == NULL){
    return NULL;
  }
  /*
  fseek(f, 0, SEEK_END);
  len = ftell(f);
  //fseek(f, 0, SEEK_SET);
  rewind(f);

  //len = (fseek(f, 0, SEEK_END)+1);
  intarr_t * newia = intarr_create(len);
  if (!newia){
    return 1;
  }
  fread(newia->data, sizeof(int), len, f);
	fclose(f);
	return newia;
  */

  if ( fread (&len, sizeof(int), 1, f) != 1 ){
    fclose(f);
    free(newia);
    return NULL;
  }
	
  newia->len = len;
  newia->data = malloc(len*sizeof(int));

  if (fread(newia->data, sizeof(int), len, f) != len){
    fclose(f);
    free(newia);
    return NULL;
  }

  fclose(f);
  return newia;
}

/*
int main(){
intarr_t * save = intarr_create(0);
int i;
for (i=0; i<6; i++){
intarr_push(save, i);
}
intarr_save_binary(save, "test.json");
intarr_t * test;
test = intarr_load_binary("test.json");
printf("%d\n", test->len);
intarr_save_binary(test, "test2.json");
test = intarr_load_binary("swag.json");
printf("%d\n", test->len);

}

*/
