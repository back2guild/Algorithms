#include "../src/stack.h"

stack_head_t *test_create_stack() {
  stack_head_t *stack = create();
  assert(stack != NULL);
  return stack;
}

void test_push(stack_head_t *stack) {
  for (int i = 1; i <= 10; i++) {
    stack_node_t *node = push(stack, i);
    assert(node != NULL);
  }
}

void test_pop(stack_head_t *stack)
{
    printf("stack size = %d\n", stack_size(stack));
    assert(stack != NULL);
    stack_node_t *node1 = pop(stack);
    assert(node1 != NULL);
    stack_node_t *node2 = pop(stack);
    assert(node2 != NULL);
    free(node1);
    free(node2);
}

void test_is_stack_empty(stack_head_t *stack)
{
    assert(is_stack_empty(stack) == true);
}

int main(int argc, char **argv) {
  if (argc > 0 && argv != NULL) {
    stack_head_t *stack = test_create_stack();
    test_push(stack);
    display_stack(stack);
    test_pop(stack);
    display_stack(stack);
    destroy(stack);
  }
  return EXIT_SUCCESS;
}