#include "binary_trees.h"
#include <stdio.h>

#define COUNT 10

/**
 * print_tree_recursive - Helper function to print the tree sideways
 * @tree: Pointer to the current node
 * @space: Current indentation level
 */
static void print_tree_recursive(const binary_tree_t *tree, int space)
{
	int i;

	if (!tree)
		return;

	space += COUNT;

	print_tree_recursive(tree->right, space);

	printf("\n");
	for (i = COUNT; i < space; i++)
		printf(" ");
	printf("(%03d)\n", tree->n);

	print_tree_recursive(tree->left, space);
}

/**
 * binary_tree_print - Prints the binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	print_tree_recursive(tree, 0);
}
