#include <criterion/criterion.h>
#include "../src/queue.h"

#define MAX_Q_SIZE 10

Test(Queue, CreateQueue) {
    Q_t *q = createQueue(MAX_Q_SIZE);
    cr_expect(q == NULL, "Q must be null");
}