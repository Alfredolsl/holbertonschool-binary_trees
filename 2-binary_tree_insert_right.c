#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert new right-child node
 * @value: value to store in the new node
 *
 * Return: pointer to the created note, NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (parent->right == NULL)
	{
		parent->right = new;
		new->parent = parent;
	}
	else
	{
		tmp = parent->right;
		parent->right = new;
		new->parent = parent;
		new->right = tmp;
		tmp->parent = new;
	}

	return (new);
}
