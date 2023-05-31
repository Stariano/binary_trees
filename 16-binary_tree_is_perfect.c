#include "binary_trees.h"
#include <stdio.h>

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

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left += 1 + binary_tree_height(tree->left);
	if (tree->right)
		right += 1 + binary_tree_height(tree->right);

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * binary_tree_is_full - A function that checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if tree is full or 0 in otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int sizee = 0;
	int height = 0;
	int result = 1.0;

	if (tree == NULL)
		return (0);

	sizee += binary_tree_size(tree);
	height += binary_tree_height(tree);
	height++;

	while (height != 0)
	{
		result *= 2;
		--height;
	}
	result--;

	if (result == sizee)
		return (1);
	return (0);
}

/**
 * binary_tree_balance - A function that measures the balance factor of a
 * binary tree.
 * @tree: Pointer to root node to calculate balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int leftsb = 0, rightsb = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		leftsb += 1 + binary_tree_balance(tree->left);
	if (tree->right)
		rightsb += 1 + binary_tree_balance(tree->right);

	return (leftsb - rightsb);
}

/**
 * binary_tree_is_perfect - A function that checks if binary tree is perfect.
 * @tree: A pointer to the root of the tree.
 * Return: 1 if binary tree is perfect or 0 in otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((binary_tree_is_full(tree) == 1) &&
			(binary_tree_balance(tree) == 0))
		return (1);
	return (0);
}
