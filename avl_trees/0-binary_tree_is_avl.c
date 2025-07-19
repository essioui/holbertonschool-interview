#include "binary_trees.h"
#include <stdlib.h> /* For abs() */
#include <limits.h>

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, or -1 if tree is NULL
 */
static int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst_util - Checks if the tree is a valid BST within limits
 * @tree: Pointer to the current node
 * @min: Minimum allowed value (exclusive)
 * @max: Maximum allowed value (exclusive)
 *
 * Return: 1 if valid BST, 0 otherwise
 */
static int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n) &&
		is_bst_util(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a tree is balanced (AVL property)
 * @tree: Pointer to the current node
 *
 * Return: 1 if balanced, 0 otherwise
 */
static int is_balanced(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid AVL, 0 otherwise (or if tree is NULL)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_bst_util(tree, INT_MIN, INT_MAX))
		return (0);

	if (!is_balanced(tree))
		return (0);

	return (1);
}
