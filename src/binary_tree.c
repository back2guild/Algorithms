#include "tree.h"
#include <stdlib.h>


struct TreeNode
{
	void *data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeHead
{
	int (*tcompare)(void *, void *);
	struct TreeNode *root;
	int size;
};

thead_t *createTree(tree_compare cmp)
{
	thead_t *tree = (thead_t *)malloc(sizeof(thead_t));
	if (tree)
	{
		tree->root = NULL;
		tree->size = 0;
		tree->tcompare = cmp;
	}
	return tree;
}

int treeSize(thead_t *tree)
{
	if(!tree)
	{
		return INVALID_TREE_SIZE;
	}
	return tree->size;
}

bool isTreeEmpty(thead_t *tree)
{
	if(!tree)
	{
		return false;
	}
	return ((treeSize(tree) > 0) ? false : true);
}

void destroy(tnode_t *node) {
	if(node)
	{
		destroy(node->left);
		destroy(node->right);
		free(node->data);
	}
}

bool destroyTree(thead_t *tree)
{
	if(!isTreeEmpty(tree))
		destroy(tree->root);
	free(tree);
}

