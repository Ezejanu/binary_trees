#include "binary_trees.h"

/**
 * get_path - gets the path of a node in a binary tree.
 * @node: The node in question.
 * @container: Data structure to store the path in.
 * Return: The number of nodes in the path.
 */
int get_path(const binary_tree_t *node, int container[])
{
	binary_tree_t *ptr;
	int count;

	ptr = (binary_tree_t *)node;
	count = -1;
	while (ptr != NULL)
	{
		count++;
		container[count] = ptr->n;
		ptr = ptr->parent;
	}
	return (count);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to th lowest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int path_1[50], path_2[50], i, j;
	binary_tree_t *ptr;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	i = get_path(first, path_1);
	j = get_path(second, path_2);

	for (; i >= 0 && j >= 0; i--, j--)
	{
		if (path_1[i] != path_2[j])
			break;
	}
	if (i < 0)
	{
		if (first->parent == second)
			return ((binary_tree_t *)second);
		else if (second->parent == first)
			return ((binary_tree_t *)first);
		return (NULL);
	}
	i++;

	ptr = (binary_tree_t *)first;
	while (i > 0)
	{
		ptr = ptr->parent;
		i--;
	}

	return (ptr);
}
