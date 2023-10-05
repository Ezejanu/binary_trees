#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes in a binary tree.
 * @tree: Pointer to the rot node of the binary tree.
 * Return: The number of nodes in the tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_is_complete - recursively checks if a binary tree is complete.
 * @tree: Pointer to the root node of the binary tree.
 * @index: Index.
 * @number_nodes: The number of nodes in the binary tree.
 * Return: 1, if the tree is complete, otherwise 0.
 */
int check_is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (check_is_complete(tree->left, 2 * index + 1, number_nodes) &&
			(check_is_complete(tree->right, 2 * index + 2, number_nodes)));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: Pointer to the root node of the binary tree.
 * Return: 1, if the binary tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_is_complete(tree, 0, count_nodes(tree)));
}
