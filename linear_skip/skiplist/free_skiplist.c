#include "../search.h"

/**
 * free_skiplist - Frees a skip list
 * @list: Pointer to the head of the list
 */
void free_skiplist(skiplist_t *list)
{
skiplist_t *tmp;

while (list)
{
    tmp = list->next;
    free(list);
    list = tmp;
}
}
