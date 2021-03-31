#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * Lista = malloc(sizeof(List));
  Lista -> head = NULL;
  Lista -> tail = NULL;
     return Lista;
}

void * firstList(List * list) {
    if (list -> head != NULL){
      list -> current = list-> head;
      return(void*) list -> head -> data;
    }
    return NULL;
}

void * nextList(List * list) {
    if(list -> current != NULL && list -> current -> next != NULL){
      list -> current = list -> current -> next;
      return(void*) list -> current -> data;
    }

    return NULL;
}

void * lastList(List * list) {
  if (list-> tail != NULL){
    list -> current = list -> tail;
    return(void*) list -> tail -> data;
  }
    return NULL;
}

void * prevList(List * list) {
  if (list-> current != NULL && list -> current -> prev !=NULL){
    list -> current = list ->current -> prev;
    return(void*) list -> current -> data;
  }
    return NULL;
}

void pushFront(List * list, const void * data) {
  Node*NuevoDato=createNode(data);
  if (list -> head != NULL){
    list -> head -> prev = NuevoDato;
    NuevoDato -> next = list -> head;
    list -> head = NuevoDato;
    list -> current = NuevoDato;
  }
  else{
    list -> head = NuevoDato;
    list -> tail = NuevoDato;
    list -> current = NuevoDato;
  
  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node*NuevoDato=createNode(data);
  if (list -> current != NULL){
    list -> current -> prev = NuevoDato;
    NuevoDato -> next = list -> current;
    list -> current = NuevoDato;
  }
  else{
    list -> head = NuevoDato;
    list -> tail = NuevoDato;
    list -> current = NuevoDato;
  
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
 
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}