#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

list_t* list_create( void )
{
  list_t* l = malloc( sizeof(list_t) );
  if( l )
    {
      l->head = NULL;
      l->tail = NULL;
    }
  return l;
}

void list_destroy( list_t* list )
{
  element_t* el = list->head;
  while( el )
    {
      element_t* next = el->next;
      free( el );
      el = next;
    }

  free( list );
}

element_t* element_create( int i )
{
  element_t* el = malloc( sizeof(element_t) );
  if( el )
    {
      el->val = i;
      el->next = NULL;
    }
  return el;
}

int list_append( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( el == NULL )
    return 1;

  if( list->head == NULL )
    list->head = el;

  if( list->tail )
    list->tail->next = el;

  list->tail = el;

  return 0;
}

int list_prepend( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( el == NULL )
    return 1;

  if( list->tail == NULL )
    list->tail = el;

  if( list->head )
    el->next = list->head;

  list->head = el;

  return 0;
}

element_t* list_index( list_t* list, unsigned int i )
{
  element_t* el = list->head;
  unsigned int now = 0;

  while( now < i )
    {
      if( el->next == NULL )
	return NULL;

      now++;
      el = el->next;
    }

  return el;
}


void list_print( list_t* list )
{
  printf( "{" );

  for( element_t* el = list->head;
       el->next;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}


int test_element_create( void )
{

	int value = 1234;

	element_t* el = malloc( sizeof( element_t ) );
	assert(el);
	memset( el, 0xFF, sizeof( element_t ) );
	free(el);

	el = element_create( value );
	assert(el);

	if( el->next )
	{
		puts( "element_create(): element->next not null" );
		return 1;
	}

	if( el->val != value )
	{
		puts( "element_create(): element->val not correct" );
		return 1;
	}

	return 0;
}


int test_list_index (list_t* list, unsigned int i)
{
	element_t* ret = list_index (list, 0);

	if (ret->val != -4 && list->head != NULL)
	{
		puts("list_index(): error for index 0");
		return 1;
	}

		ret = list_index (list, 2);

	if ( ret->val != -2 && list->head != NULL )
	{
		puts("list_index(): index 2 incorrect");
		return 1;
	}

	return 0;
}

int test_list_prepend(void)
{
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

int test_list_create()
{
	list_t* list = malloc( sizeof( list_t ) );
	assert(list);
	memset( list, 0xFF, sizeof( list_t ) );
	free(list);

	list = list_create();
	assert(list);

	if (list->head != NULL && list->tail != NULL)
	{
		puts("list_create(): failed to create list with head and tail set to NULL");
		list_destroy(list);

		return 1;
	}

	list_destroy(list);

	return 0;

}


int main( int argc, char* argv[] )
{
  list_t* list = list_create();

  for( int i=0; i<5; i++ )
    list_append( list, i );

  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );

  list_print( list );


  int index = 2;
  element_t* el = list_index( list, index );

  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1;
    }

  printf( "value at index %d is %d\n", index, el->val );

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

  list_destroy( list );

  return 0;
}
