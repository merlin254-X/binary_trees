#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	if (!first || !second)	/* Check for NULL nodes */
		return (NULL);

	if (first == second)  /* Check if nodes are the same */
		return ((binary_tree_t *)first);

	/* Recursively traverse up the tree from each node */
	binary_tree_t *p = first->parent;
	binary_tree_t *q = second->parent;

	while (p && q && p != q)
	{
		if (p->depth > q->depth)  /* Move up shorter branch */
			p = p->parent;
		else
			q = q->parent;
	}

	return (p);  /* Return the common ancestor node */
}
