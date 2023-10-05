#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_currentlevel - calls a function on the nodes at a current level.
 * @tree: Pointer to the root of the binary tree.
 * @func: Pointer to the function to tcall on the node.
 * @level: The level at which a node is to be accessed.
 */
void binary_tree_currentlevel(const binary_tree_t *tree, void (*func)(int),
				size_t level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_currentlevel(tree->left, func, level - 1);
		binary_tree_currentlevel(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 *			using level-order traversal.
 * @tree: Pointer to th root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	height = binary_tree_height(tree);

	for (i = 1; i <= height; i++)
		binary_tree_currentlevel(tree, func, i);
}
