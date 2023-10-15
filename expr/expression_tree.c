#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    void *data;
    struct BTNode *left;
    struct BTNode *right;
} bt_node__t;

typedef int (*compare) (void*, void*); 

typedef struct BTHead {
    bt_node__t *root;
    unsigned int size; // >= 0
    compare comparator;

} bt_head__t;

bool isTreeEmpty(bt_head__t *tree)
{
    return (NULL == tree ? true : ((tree->root == NULL && tree->size == 0) ? true : false));
}

bt_head__t* createTree(compare cmp) {
    bt_head__t *tree = (bt_head__t*) malloc(sizeof(bt_head__t));
    if(tree)
    {
        tree->size = 0;
        tree->comparator = cmp;
        tree->root = NULL;
    }
    else {
        fprintf(stderr, "Error: Failed to create a tree\n");
    }
    return tree;
}

bt_node__t* createTreeNode(void* data) {
    bt_node__t *node = (bt_node__t*) malloc(sizeof(bt_node__t));
    if(node) {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else {
        fprintf(stderr, "Error: Failed to create a node\n");
    }
    return node;
}


bool isOperator(char c) {
    bool result = false;
    switch (c) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':
            result = true;
            break;
        default:
            break;
    }
    return result;
}

void addNode(bt_head__t *tree, bt_node__t *node) {
    if(isTreeEmpty(tree)) {
        tree->root = node;
        tree->size += 1;
    }
}

void process(char *expr) {
    if(expr)
    {

    }
    else {
        printf("Nothing to process\n");
    }
}


int main(int argc, char **argv) {
    //a * (b + c) + d
    process("a*(b+c)+d");
}