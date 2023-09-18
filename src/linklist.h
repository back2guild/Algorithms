#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef struct LinkListNode lnode_t;
typedef struct LinkListHead lhead_t;

lhead_t* createLinkList(void);
size_t getSize(lhead_t*);
lnode_t* getHead(lhead_t*);

#endif