#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary
 * tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Traverse left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse right subtree */
	binary_tree_postorder(tree->right, func);

	/* Call the function with the node value */
	func(tree->n);
}
