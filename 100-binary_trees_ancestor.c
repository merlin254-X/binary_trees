#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *ptr;

	if (first == NULL || second == NULL)
		return (NULL);

	ptr = first;
	while (ptr != NULL)
	{
		if (binary_tree_is_descendant_of(second, ptr))
			return ((binary_tree_t *)ptr);
		ptr = ptr->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_descendant_of - Checks if a node is descendant of another
 * @node: Pointer to the node to check if it's a descendant
 * @ancestor: Pointer to the ancestor node to check
 *
 * Return: 1 if node is a descendant of ancestor, 0 otherwise
 */
int binary_tree_is_descendant_of(const binary_tree_t *node,
								 const binary_tree_t *ancestor)
{
	if (node == NULL || ancestor == NULL)
		return (0);

	while (node != NULL)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}

	return (0);
}
