#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->right->left;
	if (tree->right != NULL)
		tree->right->parent = tree;
	tree->parent->left = tree;
	return (tree->parent);
}
