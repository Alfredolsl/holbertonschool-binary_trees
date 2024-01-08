#include "binary_trees.h"

    
/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the roof node of the tree
 *
 * Return: measured height, 0 if NULL
 */

size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL) /* removed null children condition */
		return (0);

	l = _binary_tree_height(tree->left);
	r = _binary_tree_height(tree->right);

	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of tree to measure balance
 *
 * Return: calculated balance of the node
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree->left) - _binary_tree_height(tree->right));
}
