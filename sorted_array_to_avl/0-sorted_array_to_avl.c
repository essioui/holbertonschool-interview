#include "binary_trees.h"

/**
 * build_avl - Recursively builds AVL from sorted array
 * @array: The array to convert
 * @start: Start index
 * @end: End index
 * @parent: Pointer to parent node
 * Return: Pointer to created node (root)
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    root = malloc(sizeof(avl_t));
    if (!root)
        return (NULL);

    root->n = array[mid];
    root->parent = parent;
    root->left = build_avl(array, start, mid - 1, root);
    root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Pointer to array
 * @size: Size of array
 * Return: Pointer to root of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl(array, 0, (int)size - 1, NULL));
}
