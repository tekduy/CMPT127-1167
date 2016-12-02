#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

// List element: a list is a chain of these
/*typedef struct element
{
  int val;
  struct element* next;
} element_t;

// List header - keep track of the first and last list elements
typedef struct list
{
  element_t* head;
  element_t* tail;
} list_t;
*/

/*
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
  if( el != NULL)
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

  if (el != NULL){
    el->next =NULL;
    if (list->tail == NULL){
      assert(list->head == NULL);
      list->head = el;
      list->tail = el;
    }
    else{
      list->tail->next = el;
      list->tail = el;
    }
  }
}
*/

void LLappendNode(list_t * list, element_t * newNode) {
    if (newNode != NULL) {
        newNode->next = NULL;
        if (list->tail == NULL) {
            assert(list->head == NULL);
            list->head = newNode;
            list->tail = newNode;
        } else {       
            list->tail->next = newNode; 
            list->tail = newNode;
        }
    }
}

void LLappend(list_t * list, int value) {
    element_t * newNode = malloc(sizeof(element_t));
    if (newNode != NULL) {
        newNode->val = value;
        LLappendNode(list, newNode);
    }
}

void list_insertNode(list_t * list, element_t * newNode) {
    if (list->head == NULL) {
        assert(list->tail == NULL);
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
    } else if (list->head->val >= newNode->val) {
       
        newNode->next = list->head;
        list->head = newNode;
    } else {
       
        element_t * prev = list->head;
        element_t * curr = list->head->next;
        while (curr != NULL && curr->val < newNode->val) { 
            curr = curr->next;
            prev = prev->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        if (curr == NULL) {
 
            list->tail = newNode;
        }
    }
}

void LLcatenate(list_t * L1, list_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}

void list_sort(list_t * list) {
    if (list->head == list->tail) {
        return;
    }

    int pivot = list->head->val;
    element_t * pivot_node = list->head;
    list->head = list->head->next;

    list_t * first = list_create();
    list_t * second = list_create();
    element_t * curr = list->head;
    element_t * next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            LLappendNode(first, curr);
        } else {
            LLappendNode(second, curr);
        }
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;

    list_sort(first);
    list_sort(second);

    LLcatenate(list, first);
    LLappendNode(list, pivot_node);
    LLcatenate(list, second);
}
/*
void list_print( list_t* list )
{
  printf( "{" );

  for( element_t* el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}

/*
int main(){
  list_t * list;
  list = list_create();
  list_append(list, 5);
  list_append(list, 3);
  list_append(list, 1);
  for (int i=5000; i>=0; i--){
    list_append(list, i);
  }
  list_print(list);
  list_sort(list);
  list_print(list);
}
*/

