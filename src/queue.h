#ifndef _QUEUE_H_
#define _QUEUE_H_ 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include <time.h>

typedef struct Queue Q_t;

Q_t* createQueue(int);
Q_t* destroyQueue(Q_t*);

bool enqueue(Q_t*, void*);
void* dequeue(Q_t*);

void* front(Q_t*);
void* rear(Q_t*);

int qCount(Q_t*);
bool is_empty(Q_t*);
bool is_full(Q_t*);

#endif