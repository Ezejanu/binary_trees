#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to be rotated.
 * Return: Pointer to the new root node of the binary tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->left->right;
	if (tree->left != NULL)
		tree->left->parent = tree;
	tree->parent->right = tree;
	if (tree->parent->parent != NULL)
		tree->parent->parent->left = tree->parent;

	return (tree->parent);
}

