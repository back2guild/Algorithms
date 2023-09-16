#include "lifo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

LIFO_t *create(const int maxSize) {
  LIFO_t *LIFO = NULL;
  assert(maxSize > 0);
  LIFO = (LIFO_t *)malloc(sizeof(LIFO_t));
  if (LIFO) {
    LIFO->count = 0;
    LIFO->maxSize = maxSize;
    LIFO->top = -1;
    LIFO->lifoList = (void **)calloc(LIFO->maxSize, sizeof(void *));

    if (!LIFO->lifoList) {
      free(LIFO);
      LIFO = NULL;
    }
  }
  return LIFO;
}

LIFO_t *destroy(LIFO_t *lifo) {
  if (NULL != lifo) {
    if (!isempty(lifo)) {
      for (int i = 0; i < lifo->count; i++) {
        free(lifo->lifoList[i]);
        lifo->lifoList[i] = NULL;
      }
    }
    free(lifo);
    lifo = NULL;
  }
  return lifo;
}
bool push(LIFO_t *lifo, void *itemPtr) {
  bool success = false;
  assert(lifo && !isfull(lifo));
  lifo->count++;
  lifo->top++;
  lifo->lifoList[lifo->top] = itemPtr;
  success = true;
  return success;
}

void *pop(LIFO_t *lifo) {
  void *result = NULL;
  assert(lifo && !isempty(lifo));
  result = lifo->lifoList[lifo->top];
  lifo->count--;
  lifo->top--;
  return result;
}

void *top(LIFO_t *lifo) {
  assert(lifo && !isempty(lifo));
  return lifo->lifoList[lifo->top];
}

int count(LIFO_t *lifo) { return lifo->count; }

bool isempty(LIFO_t *lifo) { return (lifo->count == 0); }

bool isfull(LIFO_t *lifo) { return (lifo->count == lifo->maxSize); }

void display(LIFO_t* lifo, printer ullptr)
{
  if(lifo !=NULL && !isempty(lifo) && lifo->lifoList != NULL)
  {
    void ** lifoList = lifo->lifoList;
    for(int i = lifo->top; i>=0; i--)
    {
      void *ptr = lifoList[i];
      ullptr(ptr);
    }
    printf("\n");
  }
}