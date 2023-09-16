#ifndef _LIFO_H_
#define _LIFO_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include <time.h>

typedef struct {
  void **lifoList;
  int count;
  int maxSize;
  int top;
} LIFO_t;

typedef void (*printer)(void*);

LIFO_t *create(int maxSize);
LIFO_t *destroy(LIFO_t *lifo);
bool push(LIFO_t *lifo, void *itemPtr);
void *pop(LIFO_t *lifo);
void *top(LIFO_t *lifo);
int count(LIFO_t *lifo);
bool isempty(LIFO_t *lifo);
bool isfull(LIFO_t *lifo);
void display(LIFO_t*, printer);
#endif