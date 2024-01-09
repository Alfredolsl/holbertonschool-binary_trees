#include "binary_trees.h"

/**
 * __binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the roof node of the tree
 *
 * Return: measured height, 0 if NULL
 */

size_t __binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = __binary_tree_height(tree->left);
	r = __binary_tree_height(tree->right);

	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}

/**
 * _binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of tree to measure balance
 *
 * Return: calculated balance of the node
 */

int _binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (__binary_tree_height(tree->left) - __binary_tree_height(tree->right));
}

/**
 * sub_tree_perfect - determines if a sub_tree is perfect
 * @tree: pointer to the subtree to check
 *
 * Return: 1 if perfect, otherwise 0
 */

int sub_tree_perfect(const binary_tree_t *tree)
{
	if (tree && !tree->left && !tree->right)
		return (1);

	if (tree && tree->right && tree->left)
		return (sub_tree_perfect(tree->left) &&
				sub_tree_perfect(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of tree to check
 *
 * Return: 1 if perfect, otherwise 0
 * if NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (_binary_tree_balance(tree) != 0)
		return (0);

	return (sub_tree_perfect(tree->left) && sub_tree_perfect(tree->right));
}
