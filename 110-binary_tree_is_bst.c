#include "binary_trees.h"

/**
 * get_max_value - Finds the maximum value in a binry tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: The maximum value in the binary tree.
 */
int get_max_value(const binary_tree_t *tree)
{
	int left, right, max = 0;

	if (tree == NULL)
		return (0);

	left = get_max_value(tree->left);
	right = get_max_value(tree->right);

	if (left > right)
		max = left;
	else
		max = right;

	if (max < tree->n)
		max = tree->n;

	return (max);
}

/**
 * get_min_value - Finds the minimum value in a binary tree.
 * @tree: Pointer to the root of the binary tree.
 * Return: The minimum vlue in the binary tree.
 */
int get_min_value(const binary_tree_t *tree)
{
	int left, right, min = 0;

	if (tree == NULL)
		return (1000000000);

	left = get_min_value(tree->left);
	right = get_min_value(tree->right);

	if (left < right)
		min = left;
	else
		min = right;

	if (min > tree->n)
		min = tree->n;

	return (min);
}


/**
 * is_valid_bst - checks that a binary tree is a valid Binary Search Tree.
 * @tree: Pointer ot the root node of the binary tree.
 * Return: 1 if it is a BST, otherwise 0.
 */
int is_valid_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL &&
			(get_max_value(tree->left) > tree->n))
		return (0);

	if (tree->right != NULL &&
			(get_min_value(tree->right) < tree->n))
		return (0);

	if (!is_valid_bst(tree->left) || !is_valid_bst(tree->right))
		return (0);

	return (1);
}


/**
 * binary_tree_is_bst - checks that a binary tree is aBinary Search Tree.
 * @tree: Pointer to the root node of the tree.
 * Return: 1, if it is a BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree));
}
