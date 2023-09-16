#include "../src/lifo.h"

#define SIZE 15

LIFO_t *test_create_lifo() {
  LIFO_t *stack = create(SIZE);
  assert(stack != NULL);
  assert(stack->count == 0 && stack->top == -1);
  // assert(sizeof(*(stack->lifoList)) == 15);
  return stack;
}

void print_ull(void *listPtr, int maxSize) {
  assert(listPtr != NULL && maxSize > 0);
  unsigned long long *list =((unsigned long long *)listPtr);
  for (int i = 0; i < maxSize; i++) {
    printf("value = %llu, address = %p\n", (unsigned long long)(*(list + i)), (list + i));
  }
  printf("\n");
}

void test_push(LIFO_t *stack) {
  time(NULL);
  for (int i = 0; i < SIZE; i++) {
    unsigned long long *temp =
        (unsigned long long *)malloc(sizeof(unsigned long long));
    if (temp) {
      *temp = ((rand() % (SIZE - 1 + 1)) + 1);
      //printf("inserting %llu, address = %p\t", *temp, temp);
      assert(push(stack, temp) == true);
      //printf(" ---> %llu\n", *((unsigned long long*) top(stack)));
    } else {
      printf("Failed to create LIFO node\n");
    }
  }
}

void test_display(void *ptr)
{
  unsigned long long *ullPtr = (unsigned long long *) ptr;
  printf("%llu\t", *ullPtr);
}


void test_pop(void *ptr)
{
  assert(*((unsigned long long*) top(ptr)) == *((unsigned long long*) pop(ptr)));
}

int main(int argc, char **argv) {
  if (argc == 1 && argv != NULL) {
    LIFO_t *stack = test_create_lifo();
    test_push(stack);
    display(stack, test_display);
    destroy(stack);
  }
}