//
//  stack.c
//  Research
//
//  Created by Rahul Chaudhary on 31/08/23.
//

#include "stack.h"
#include <stdio.h>

struct StackNode {
  int number;
  struct StackNode *previous;
  struct StackNode *next;
};

struct StackHead {
  unsigned int size;
  struct StackNode *top;
};

stack_head_t *create() {
  stack_head_t *stack = (stack_head_t *)malloc(sizeof(stack_head_t));
  if (stack) {
    stack->size = 0;
    stack->top = NULL;
  }
  return stack;
}
void destroy(stack_head_t *stack) {
  if (stack && !is_stack_empty(stack)) {
    while (stack->top != NULL) {
      stack_node_t *temp = stack->top;
      stack->top = temp->previous;
      stack->size -= 1;
      free(temp);
    }
    free(stack);
  }
}

stack_node_t *create_node(int value) {
  stack_node_t *node = (stack_node_t *)malloc(sizeof(stack_node_t));
  if (node) {
    node->number = value;
    node->previous = NULL;
    node->next = NULL;
  }
  return node;
}

bool is_stack_empty(stack_head_t *stack) {
  return stack == NULL || (stack->size == 0 && stack->top == NULL);
}

stack_node_t *push(stack_head_t *stack, int data) {
  stack_node_t *node = NULL;
  if (stack != NULL) {
    node = create_node(data);
    if (node) {
      if (!is_stack_empty(stack)) {
        node->previous = stack->top; 
      }
      stack->top = node;
      stack->size += 1;
    }
  }
  return node;
}

stack_node_t* pop(stack_head_t *stack) {
  stack_node_t *node = NULL;
  if(stack != NULL && !is_stack_empty(stack))
  {
    node = stack->top;
    stack->top = stack->top->previous;
    stack->size -= 1;
  }
  return node;
}

void display_stack(stack_head_t *stack) {
  if(stack && !is_stack_empty(stack))
  {
    stack_node_t *node = stack->top;
    while(node != NULL)
    {
      printf("%d\t", node->number);
      node = node->previous;
    }
    printf("\n");
  }
}

unsigned int stack_size(stack_head_t *stack) {
  return stack->size;
}
