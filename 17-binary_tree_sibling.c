#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node.
 * @node: The node to find sibling for.
 * Return: A pointer to sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sib, *parent;

	parent = node->parent;

	if (node == NULL || parent == NULL)
		return (NULL);

	sib = parent->left;

	if (sib == node)
		return (parent->right);

	return (parent->left);
}
