#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree using level-order
 * traversal and calls the given function for each visited node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* Create a queue for level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (!queue)
		return;

	int front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		front++;

		func(current->n);

		/* Enqueue left child */
		if (current->left)
		{
			queue[rear] = current->left;
			rear++;
		}

		/* Enqueue right child */
		if (current->right)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
