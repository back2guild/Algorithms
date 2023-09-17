#include <criterion/criterion.h>
#include "../src/queue.h"

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

Test(Queue, CreateQueue) {
    Q_t *q = createQueue(MAX_Q_SIZE);
    cr_expect(q != NULL, "Q must not be null");

    q = destroyQueue(q);
    cr_expect(q == NULL, "Q must be null");
}

Test(Queue, DestroyQueue) {
    Q_t *q = createQueue(MAX_Q_SIZE);
    cr_expect(q != NULL, "Q must not be null");

    q = destroyQueue(q);
    cr_expect(q == NULL, "Q must be null");
}

