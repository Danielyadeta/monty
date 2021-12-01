#include "monty.h"

/**
* op_mod - computes the rest of the division\
*	of the second top element of the stack\
*	by the top element of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_mod(stack_t **h)
{
	int a;

	a = op_pop(h);
	if (a == 0)
		printerr("number is 0");

	(*h)->n = (*h)->n % a;

	return (1);
}

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: Always Void
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
