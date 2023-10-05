#include "binary_trees.h"

/**
 * binary_tree_heights - measures the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: the height of the binary tree.
 */
size_t binary_tree_heights(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_heights(tree->left);
	right_height = binary_tree_heights(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* node_count - a function to count the no of nodes in a binary tree
* @tree: Pointer to the root node of the binary tree
* Return: the number of nodes
*/
int node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0, if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_heights(tree);

	if ((1 < tree_height) - 1 == node_count(tree))
		return (1);
	else
		return (0);
}
