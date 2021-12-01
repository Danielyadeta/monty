#include "monty.h"

/**
 * add_dnodeint - add a new node at the beginning of a dlistint_t list
 * @head: double pointer to head of linked list
 * @n: value to the new node
 *
 * Return: pointer to the new node, otherwise NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
/*	if (head == NULL || new == NULL)
		return (NULL);
*/
	new->prev = NULL;
	new->next = *head;
	new->n = n;
	*head = new;
	if (new->next != NULL)
		(new->next)->prev = new;
	return (new);
}

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to a dlistint_t list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
