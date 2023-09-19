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

bool isEmpty(head_t *tree) {
    return (NULL == tree->root && 0 == tree->size);
}

void _insert(head_t *tree, node_t *root, node_t *node) {
    if(NULL != tree && NULL != root) {
        if(tree->compare(root, node) == 0) {
            
        }
        else if(tree->compare(root, node) < 0) {
            _insert(tree, root->left, node);
        }
        else {
            _insert(tree, root->right, node);
        }
    }
}

bool insertBST(head_t *tree, node_t *node) {
    bool success = false;
    if(isEmpty(tree)) {
        tree->root = node;
    }
    else {
        _insert(tree, tree->root, node);
    }
    tree->size++;
    success = true;
    return success;
}
