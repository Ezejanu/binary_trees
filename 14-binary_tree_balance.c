#include "binary_trees.h"



/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - a function that measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor, or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
