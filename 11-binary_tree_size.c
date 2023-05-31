#include "binary_trees.h"

/**
 * binary_tree_size - that measures the size of a binary tree
 * @tree: pointer node binary tree
 * Return: measures the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t height = 1;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height += binary_tree_size(tree->left);
	if (tree->right)
		height += binary_tree_size(tree->right);
	return (height);
}
