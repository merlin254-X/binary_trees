#include "binary_trees.h"


/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *							traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node. The value in the node
 *		  must be passed as a parameter to this function.
 *
 * Description: If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	size_t front = 0, rear = 0;

	/* Enqueue root and initialize queue */
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		/* Dequeue node and print it */
		const binary_tree_t *temp = queue[front++];

		func(temp->n);

		/* Enqueue left child */
		if (temp->left != NULL)
			queue[rear++] = (binary_tree_t *)temp->left;

		/* Enqueue right child */
		if (temp->right != NULL)
			queue[rear++] = (binary_tree_t *)temp->right;
	}

	/* Free the dynamically allocated queue */
	free(queue);
}
