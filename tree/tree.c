#include "tree.h"


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
	return ((treeSize(tree) > 0) ? true : false);
}
