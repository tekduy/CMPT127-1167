#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

int test_element_create( void ){
	int value = 1234;

	element_t* el = malloc( sizeof( element_t ) );
	assert(el);
	memset( el, 0xFF, sizeof( element_t ) );
	free(el);

	el = element_create( value );
	assert(el);

	if( el->next ){
		puts( "element_create(): element->next not null" );
		return 1;
	}

	if( el->val != value ){
		puts( "element_create(): element->val not correct" );
		return 1;
	}

	return 0;
}

int test_list_index2 (list_t* list, unsigned int i){
	element_t * ret = list_index(list, i);
	if (ret != NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int test_list_index(list_t* list, unsigned int i){

	element_t* ret = list_index (list, 0);

	if (ret->val != -4 && list->head != NULL){
		puts("list_index(): error for index 0");
		return 1;
	}

		ret = list_index (list, 2);

	if ( ret->val != -2 && list->head != NULL ){
		puts("list_index(): index 2 incorrect");
		return 1;
	}

	return 0;
}

int test_list_append(void){
	list_t* empty = list_create();
	list_append(empty, 5);

	if (empty->head == NULL)
	{
		puts("list_append(): error when append el to empty list");
		return 1;
	}
	else if (empty->tail == NULL){
		puts("list_append(): error when append el to empty list");
		return 1;
	}

	list_destroy(empty);
	return 0;
}

int test_list_prepend(void){
	list_t* empty = list_create();
	list_prepend(empty, 5);

	if (empty->tail == NULL)
	{
		puts("list_prepend(): error when prepend el to empty list");

		return 1;
	}

	list_destroy(empty);
	return 0;
}


int test_list_create(){
	list_t* list = malloc( sizeof( list_t ) );
	assert(list);
	memset( list, 0xFF, sizeof( list_t ) );
	free(list);

	list = list_create();
	assert(list);

	if (list->head != NULL && list->tail != NULL){
		puts("list_create(): failed to create list with head and tail set to NULL");
		printf("Empty list\n");
		list_destroy(list);

		return 1;
	}

	list_destroy(list);

	return 0;
}

int main( int argc, char* argv[] ){
  list_t* list = list_create();

  for( int i=0; i<5; i++ ){
    list_append( list, i );
	}

  for( int i=-1; i>-5; i-- ){
    list_prepend( list, i );
	}

  list_print( list );

  int index = 2;
  element_t* el = list_index( list, index );

  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1;
    }

	else{
  printf( "The value at index %d is %d\n", index, el->val );
	}

	list_t* list2 = list_create();
	list_print(list2);
	element_t * el2 = list_index (list2, 0);
	element_t * el3 = list_index (list2, 2);

  if( el->val != -2 )
    return 1;

	if ( test_element_create() == 1)
	{
		return 1;
	}

	if ( test_list_index (list, 0) == 1 )
	{
		return 1;
	}

	if ( test_list_prepend() == 1)
	{
		return 1;
	}

	if ( test_list_create() == 1)
	{
		return 1;
	}

	if (test_list_append() == 1){
		return 1;
	}

  list_destroy( list );

  return 0;
}
