#include "queue.h"

struct Queue {
    int maxSize;
    int count;
    int front;
    int rear;
    void **qArray;
};

Q_t* createQueue(int maxSize) {
    return NULL;
}


Q_t* destroyQueue(Q_t *q) {
    return NULL;
}

bool enqueue(Q_t *q , void *ptr)
{
    return false;
}


void* dequeue(Q_t *q) {
    return NULL;
}

void* front(Q_t *q) {
    return NULL;
}


void* rear(Q_t *q) {
    return NULL;
}

int qCount(Q_t *q) {
    return q->count;
}


bool is_empty(Q_t *q) {
    return (q->count == 0);
}


bool is_full(Q_t *q) {
    return (q->count == q->maxSize);
}