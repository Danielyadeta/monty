#include "monty.h"

/**
 * len_stack - returns the number of elements in a linked dlistint_t list
 * @h: pointer to a dlistint_t list
 *
 * Return: the number of nodes
 */
size_t len_stack(const stack_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * free_stack - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: Always Void
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
