#ifndef _TREE_H_
#define _TREE_H_
	
	// Define header files
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include <stdbool.h>

	#define INVALID_TREE_SIZE -1

	typedef int (*tree_compare) (void*, void*); 	
	typedef struct TreeHead thead_t;
	typedef struct TreeNode tnode_t;

	thead_t* createTree(tree_compare);
	int treeSize(thead_t*);
#endif
