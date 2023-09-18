#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef struct LinkListNode lnode_t;
typedef struct LinkListHead lhead_t;

lhead_t* createLinkList(void);
<<<<<<< HEAD
size_t getSize(lhead_t*);
lnode_t* getHead(lhead_t*);
=======
>>>>>>> 9460da3f726b47576d49d1e17a08bada442fa9ab

#endif