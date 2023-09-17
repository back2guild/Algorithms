#include "queue.h"

struct Queue {
    int maxSize;
    int count;
    int front;
    int rear;
    void **qArray;
};

Q_t* createQueue(int maxSize) {
    Q_t *q = NULL;
    assert(maxSize > 0);
    q = (Q_t*) malloc(sizeof(Q_t));
    if(q)
    {
        q->count = 0;
        q->front = -1;
        q->rear = -1;
        q->maxSize = maxSize;
        q->qArray = (void**) calloc(q->maxSize, sizeof(void*));
        if(!q->qArray)
        {
            fprintf(stderr, "Queue creation failed");
            free(q);
            q = NULL;
        }
    }
    return q;
}


Q_t* destroyQueue(Q_t *q) {
    if(q)
    {
        int c = q->front;
        while(q->count != 0)
        {
            free(q->qArray[c++]);
            q->count--;
            if(c == q->maxSize)
                c = 0;
        }
        free(q->qArray);
        q->qArray = NULL;
        free(q);
        q = NULL;
    }
    return q;
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