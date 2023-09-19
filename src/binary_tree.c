#include "tree.h"

struct NodeElement {
    void *data;
    struct NodeElement *left;
    struct NodeElement *right;
};

struct RootElement {
    int size;
    struct NodeElement *root;
    void (*printer)(void*);
};

