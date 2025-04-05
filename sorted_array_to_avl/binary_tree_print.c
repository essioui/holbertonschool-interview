#include "binary_trees.h"

/* Original code by Alexandre Gautier, Holberton School */

#define SPACE 10

/**
 * print_tree - Recursive function to print tree
 * @tree: Pointer to node
 * @space: Space from margin
 */
void print_tree(const binary_tree_t *tree, int space)
{
int i;

if (tree == NULL)
return;

space += SPACE;

print_tree(tree->right, space);

printf("\n");
for (i = SPACE; i < space; i++)
printf(" ");
printf("(%03d)\n", tree->n);

print_tree(tree->left, space);
}

/**
 * binary_tree_print - Wrapper to print_tree
 * @tree: Pointer to tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
print_tree(tree, 0);
}
