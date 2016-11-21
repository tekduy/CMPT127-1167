#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.
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

// frees all the memory used by the list
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

// returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
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

// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i )
{
	element_t* el = element_create( i );

	if( el == NULL )
	{
		return 1;
	}

	if( list->head == NULL )
	{
		list->head = el;
	}

	if( list->tail )
	{
		list->tail->next = el;
	}

	list->tail = el;
	return 0;
}

// Prepends a new element containing integer i to the head of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i )
{
	element_t* el = element_create( i );

	if( el == NULL )
	{
	return 1;
	}

	if( list->tail == NULL )
	{
	list->tail = el;
	}

	if( list->head )
	el->next = list->head;

	list->head = el;

	return 0;
}

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range (i.e. larger
// than (number of list elements -1 ))
element_t* list_index( list_t* list, unsigned int i )
{
	if( list->head == NULL )
	{
	return NULL;
	}

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

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list )
{
	printf( "{" );

	for( element_t* el = list->head;
	el;
	el = el->next )
	printf( " %d", el->val );

	printf( " }\n" );
}
