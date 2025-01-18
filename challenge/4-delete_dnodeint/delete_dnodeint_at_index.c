#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a dlistint_t list
 * @head: A pointer to the pointer of the first node
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    for (p = 0; current != NULL && p < index; p++)
        current = current->next;

    if (current == NULL)
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}

