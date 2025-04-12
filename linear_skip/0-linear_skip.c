#include "search.h"

/**
 * linear_skip - Search for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node, *end;

if (!list)
return (NULL);

node = list;
end = list->express;

/* Use express lane to narrow down the search range */
while (end)
{
printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
if (end->n >= value)
break;

node = end;
end = end->express;
}

/* If express lane ended, search to the end of list */
if (!end)
{
end = node;
while (end->next)
end = end->next;
}

printf("Value found between indexes [%lu] and [%lu]\n", node->index, end->index);

/* Linear search in the range */
while (node && node->index <= end->index)
{
printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
if (node->n == value)
return (node);
node = node->next;
}

return (NULL);
}
