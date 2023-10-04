#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: The number of nodes in the binary tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
		return (0);

	left_size = binary_tree_nodes(tree->left);
	right_size = binary_tree_nodes(tree->right);

	return (left_size + right_size + 1);
}
