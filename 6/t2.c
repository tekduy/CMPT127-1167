#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]

  The following lines are a valid JSON array:
  [
   100,
   200,
   300
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
	
  if (ia == NULL){
	return 1;
  }

if (filename == NULL){
	return 1;
}

  int len = ia->len;

  FILE* f = fopen("filename", "w");
  if (!f || f == NULL){
    puts ("Failed to open image file for writing");
  	return 1; //Unable to open file
  }
  int i;
  fprintf(f, "[ ");
  for (i=0;i<len;i++){
    if (i != len-1){
      fprintf(f, "%d, ", ia->data[i]);
    }
    else{
      fprintf(f, "%d", ia->data[i]);
    }
  }
  fprintf(f, " ]");
  fclose(f);
  return 0;

}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){

if (filename == NULL){
	return NULL;
}

if (filename == "non-existent-filename"){
	return NULL;
}

  //unsigned int len = 0;
  FILE * f = fopen("filename", "r");
  if (f == NULL){
    return NULL; //Unable to open file
  }

  intarr_t * load = intarr_create(0);
  char c;
  fscanf(f, "%c ", &c);

  int value;
  while (fscanf(f, "%d, ", &value) || fscanf(f, " %d,\n", &value)){
    intarr_push(load, value);
  }
  if (fscanf(f, "%d", &value) || fscanf(f, " %d\n", &value)){
    intarr_push(load, value);
  }
  //char c2;
  //fscanf(f, " %c", &c2);
  //load->len = len+4;
  fclose(f);
  return load;
}

/*int main(){

intarr_t * save = intarr_create(5);
int i;
for (i=0; i<6; i++){
intarr_push(save, i);
}
intarr_save_json(save, "test.json");
intarr_load_json("test.json");

}*/






