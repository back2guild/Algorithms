#include "tree.h"

struct NodeElement {
    void *data;
    struct NodeElement *left;
    struct NodeElement *right;
};

struct RootElement {
    int size;
    struct NodeElement *root;
    void (*printer)(node_t*);
    int (*compare)(node_t*, node_t*);
};


head_t* createBST(int (*cmp)(node_t*, node_t*), void (*printer)(node_t*)) {
    head_t *tree = (head_t*) malloc(sizeof(head_t));
    assert(NULL != tree);
    tree->root = NULL;
    tree->size = 0;
    tree->printer = printer;
    tree->compare = cmp;
    return tree;
}
