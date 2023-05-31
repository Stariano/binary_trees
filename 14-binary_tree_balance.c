#include "binary_trees.h"

/**
 * binary_tree_balance - A function that measures the balance factor of a
 * binary tree.
 * @tree: Pointer to root node to calculate balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t leftsb = 0, rightsb = 0;

	if (tree == NULL)
		return (0);

	leftsb += 1 + binary_tree_balance(tree->left);
	rightsb += 1 + binary_tree_balance(tree->right);

	return (leftsb - rightsb);
}
