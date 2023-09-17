#include <criterion/criterion.h>
#include "../src/queue.h"
#include<stdint.h>

#define MAX_Q_SIZE 10

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

Test(Queue, FailCreateQueueWithExtremeSize)
{
    Q_t *q1 = createQueue(__INT_MAX__);
    Q_t *q2 = createQueue(__INT_MAX__);
    Q_t *q3 = createQueue(__INT_MAX__);
    Q_t *q4 = createQueue(__INT_MAX__);
    cr_expect(q != NULL, "Q must not be null");

    q1 = destroyQueue(q1);
    q2 = destroyQueue(q2);
    q3 = destroyQueue(q3);
    q4 = destroyQueue(q4);
    cr_expect(q4 == NULL, "Q must be null");
}

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
            // printf("inserting %llu, address = %p\t", *temp, temp);
            cr_expect(enqueue(q, temp) == true, "Must not fail to enqueue element");
            // printf(" ---> %llu\n", *((unsigned long long*) top(stack)));
        }
        else
        {
            printf("Failed to create LIFO node\n");
        }
    }
    cr_expect(enqueue(q, temp) == false, "Must fail to enqueue element");
}
