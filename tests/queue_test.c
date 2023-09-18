#include <criterion/criterion.h>
#include "../src/queue.h"

#define MAX_Q_SIZE 10
#define EXTREME_Q_SIZE 47483647

Q_t *q = NULL;

void setup(void)
{
    q = createQueue(MAX_Q_SIZE);
    printf("Starting test setup\n");
}

void teardown(void)
{
    q = destroyQueue(q);
    printf("Completing test teardown\n");
}

Test(Queue, CreateQueue)
{
    Q_t *q = createQueue(MAX_Q_SIZE);
    cr_expect(q != NULL, "Q must not be null");

    q = destroyQueue(q);
    cr_expect(q == NULL, "Q must be null");
}

void eq(Q_t* q, const int SIZE)
{
    time(NULL);
    unsigned long long *temp = NULL;
    for (int i = 0; i < SIZE; i++)
    {
        temp = 
            (unsigned long long *)malloc(sizeof(unsigned long long));
        if (temp)
        {
            *temp = ((rand() % (SIZE - 1 + 1)) + 1);
            cr_expect(enqueue(q, temp) == true, "Must not fail to enqueue element");
        }
        else
        {
            printf("Failed to create LIFO node\n");
        }
    }
    cr_expect(enqueue(q, temp) == false, "Must fail to enqueue element");
}

/*

Test(Queue, FailEnqueueWithExtremeSize)
{
    Q_t *q1 = createQueue(EXTREME_Q_SIZE);
    eq(q1);

    Q_t *q2 = createQueue(EXTREME_Q_SIZE);
    eq(q2);

    Q_t *q3 = createQueue(EXTREME_Q_SIZE);
    eq(q3);
    
    Q_t *q4 = createQueue(EXTREME_Q_SIZE);
    eq(q4);

    q1 = destroyQueue(q1);
    cr_expect(q1 == NULL, "Q must be null");
    q2 = destroyQueue(q2);
    cr_expect(q2 == NULL, "Q must be null");
    q3 = destroyQueue(q3);
    cr_expect(q3 == NULL, "Q must be null");
    q4 = destroyQueue(q4);
    cr_expect(q4 == NULL, "Q must be null");
}


Test(Queue, FailCreateQueueWithExtremeSize)
{
    Q_t *q1 = createQueue(EXTREME_Q_SIZE);
    cr_expect(q1 != NULL, "Q1 must not be null");
    Q_t *q2 = createQueue(EXTREME_Q_SIZE);
    cr_expect(q2 != NULL, "Q2 must not be null");
    Q_t *q3 = createQueue(EXTREME_Q_SIZE);
    cr_expect(q3 != NULL, "Q3 must not be null");
    Q_t *q4 = createQueue(EXTREME_Q_SIZE);
    cr_expect(q4 != NULL, "Q4 must not be null");

    q1 = destroyQueue(q1);
    cr_expect(q1 == NULL, "Q must be null");
    q2 = destroyQueue(q2);
    cr_expect(q2 == NULL, "Q must be null");
    q3 = destroyQueue(q3);
    cr_expect(q3 == NULL, "Q must be null");
    q4 = destroyQueue(q4);
    cr_expect(q4 == NULL, "Q must be null");
}
*/

Test(Queue, DestroyQueue)
{
    Q_t *q = createQueue(MAX_Q_SIZE);
    cr_expect(q != NULL, "Q must not be null");

    q = destroyQueue(q);
    cr_expect(q == NULL, "Q must be null");
}

Test(Queue, Enqueue, .init = setup, .fini = teardown)
{
    time(NULL);
    unsigned long long *temp = NULL;
    for (int i = 0; i < MAX_Q_SIZE; i++)
    {
        temp = 
            (unsigned long long *)malloc(sizeof(unsigned long long));
        if (temp)
        {
            *temp = ((rand() % (MAX_Q_SIZE - 1 + 1)) + 1);
            cr_expect(enqueue(q, temp) == true, "Must not fail to enqueue element");
        }
        else
        {
            printf("Failed to create LIFO node\n");
        }
    }
    cr_expect(enqueue(q, temp) == false, "Must fail to enqueue element");
}

Test(Queue, FrontAndRear, .init=setup, .fini = teardown)
{
    unsigned long long *temp1 = (unsigned long long *)malloc(sizeof(unsigned long long));
    *temp1 = 10L;

    unsigned long long *temp2 = (unsigned long long *)malloc(sizeof(unsigned long long));
    *temp2 = 20L;

    enqueue(q, temp1);
    enqueue(q, temp2);

    cr_expect(*temp1 == *((unsigned long long*) front(q)), "Front must be 10L");
    cr_expect(*temp2 == *((unsigned long long*) rear(q)), "Rear must be 20L");
}