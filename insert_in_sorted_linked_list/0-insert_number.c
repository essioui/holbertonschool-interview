#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * Function to insert a new number into a sorted singly linked list
 * singly linked list: have one index just next
 * but Doubly Linked Lists have two index next and previous
 * 1/ we use malloc for reserved new memory of node
 * 2/ we add node in head when is NULL
 * 3/ we search by while position of node
 * 4/ insert new node in list
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new_node, *current;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = number;
new_node->next = NULL;

if (*head == NULL || (*head)->n >= number)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

current = *head;
while (current->next != NULL && current->next->n < number)
{
current = current->next;
}

new_node->next = current->next;
current->next = new_node;
return (new_node);
}
