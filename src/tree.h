#ifndef _TREE_H_
#define _TREE_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>

    typedef struct RootElement head_t;
    typedef struct NodeElement node_t;

    head_t* createBST(int (*cmp)(node_t*, node_t*), void (*printer)(node_t*));
    bool isEmpty(head_t*);
#endif