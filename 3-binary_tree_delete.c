#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: This function deletes an entire binary tree starting from the
 * given root node. It uses post-order traversal to delete each node and free
 * the memory allocated for it.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Post-order traversal to delete nodes */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Delete current node */
	free(tree);
}
