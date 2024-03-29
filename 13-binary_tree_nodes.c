#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a tree
 * @tree: pointer to root node of the tree to count
 *
 * Return: counted nodes, 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}
