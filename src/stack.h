#ifndef __stack_h_
#define __stack_h_

#include "common.h"

typedef struct StackNode stack_node_t;
typedef struct StackHead stack_head_t;

stack_head_t* create();
stack_node_t* create_node(int);
void destroy(stack_head_t*);
bool is_stack_empty(stack_head_t*);
stack_node_t* push(stack_head_t*, int);
stack_node_t* pop(stack_head_t*);
void display_stack(stack_head_t*);
unsigned int stack_size(stack_head_t*);
#endif /* stack_h */
