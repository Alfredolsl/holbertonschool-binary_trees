#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: node value
 *
 * Return: created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	
	if (value < parent->n)
	{
		if (parent->left == NULL)
			parent->left = new;
	}
	else if (value > parent->n)
	{
		if (parent->right == NULL)
			parent->right = new;
	}

	return (new);	
}
