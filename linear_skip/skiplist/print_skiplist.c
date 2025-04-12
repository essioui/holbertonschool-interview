#include "../search.h"

/**
 * print_skiplist - Prints the skip list with express lanes
 * @list: Pointer to the head of the list
 */
void print_skiplist(const skiplist_t *list)
{
const skiplist_t *node;

printf("List:\n");
for (node = list; node; node = node->next)
    printf("Index[%lu] = [%d]\n", node->index, node->n);
}
