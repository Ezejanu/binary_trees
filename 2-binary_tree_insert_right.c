#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of parent node.
 * @parent: Pointer to the parent node of the new node to be created.
 * @value: The value the new node is to contain.
 *
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = parent->right;
	new_node->parent = parent;
	parent->right = new_node;
	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	return (new_node);
}
