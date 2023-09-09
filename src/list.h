#ifndef _LIST_H_
#define _LIST_H_ 1
#define NULL_LIST_SIZE -1L
#include "common.h"



typedef struct Element element_t;
typedef struct RootElement root_element_t;


root_element_t* create_linklist(void);
unsigned long long get_list_size(root_element_t*);
bool add_at_front(root_element_t*, element_t*);
bool add_at_rear(root_element_t*, element_t*);
void append(root_element_t*, element_t*);
bool is_empty(root_element_t*);
void display(root_element_t*);
void clean(root_element_t*);
void droot(root_element_t*);

element_t* create_element(unsigned long long);
#endif