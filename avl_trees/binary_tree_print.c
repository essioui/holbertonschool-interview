#include "binary_trees.h"
#include <stdio.h>

#define COUNT 10

/**
 * print_tree_recursive - helper to print the tree sideways
 * @tree: pointer to the current node
 * @space: current indentation level
 */
static void print_tree_recursive(const binary_tree_t *tree, int space)
{
    if (!tree)
        return;

    space += COUNT;

    print_tree_recursive(tree->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("(%03d)\n", tree->n);

    print_tree_recursive(tree->left, space);
}

/**
 * binary_tree_print - prints the binary tree in a rotated fashion
 * @tree: pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
    print_tree_recursive(tree, 0);
}
