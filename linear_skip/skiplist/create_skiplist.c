#include "../search.h"
#include <math.h>
#include <stdio.h>

/**
 * create_skiplist - Creates a skip list with express links
 * @array: Array of integers to convert
 * @size: Size of the array
 * Return: Pointer to the head of the list
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
skiplist_t *head = NULL, *node = NULL, *last = NULL;
size_t i, step, express_i = 0, count = 0;

if (!array || size == 0)
    return (NULL);

step = sqrt(size);

for (i = 0; i < size; i++)
{
    node = malloc(sizeof(skiplist_t));
    if (!node)
        return (NULL);

    node->n = array[i];
    node->index = i;
    node->next = NULL;
    node->express = NULL;

    if (!head)
        head = node;
    else
        last->next = node;

    last = node;

    if (count % step == 0)
    {
        if (express_i != 0)
        {
            skiplist_t *tmp = head;
            while (tmp && tmp->index < express_i)
                tmp = tmp->next;
            if (tmp)
                tmp->express = node;
        }
        express_i = i;
    }

    count++;
}

return (head);
}
