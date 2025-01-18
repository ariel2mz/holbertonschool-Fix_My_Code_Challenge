#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: A pointer to the pointer of the first node of the list
 * @n: The integer to store in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new, *current;

    if (head == NULL)
        return (NULL);

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return (new);
    }

    current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = new;
    new->prev = current;

    return (new);
}
