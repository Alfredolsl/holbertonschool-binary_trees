#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent - pointer to the node to insert the left-child in
 * @value: value in new node
 *
 * Return: pointer to the new node, NULL on failure
 * or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	tmp = parent;
	
	if (tmp->left == NULL)
	{
		tmp->left = new;
		new->parent = tmp;
	}
	else
	{
		tmp = parent->left;
		parent->left = new;
		new->parent = parent;
		
		new->left = tmp;
		tmp->parent = new;
	}

	return (new);
}
