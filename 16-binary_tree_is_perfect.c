#include "binary_trees.h"
#include <math.h>

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
 * exponential_two - a function to find the powers of 2
 * @exponent: the power of 2 to be calculated
 * Return: the power of 2
 */
int exponential_two(int exponent)
{
	int i;
	int result = 1;

	for (i = 0; i < exponent; ++i)
		result *= 2;
	return (result);
}
/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0, if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height, expected_nodes;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_heights(tree);
	expected_nodes = exponential_two(tree_height) - 1;

	if (expected_nodes == node_count(tree))
		return (1);
	else
		return (0);
}
