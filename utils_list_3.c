#include "monty.h"

/**
* op_mod - computes the rest of the division\
*	of the second top element of the stack\
*	by the top element of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_mod(stack_t **h, int lnum)
{
	int a;

	if (dlistint_len(*h) < 2)
		printerr(14, lnum, NULL);
	a = op_pop(h, lnum);
	if (a == 0)
		printerr(12, lnum, NULL);

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

/**
* op_pchar - prints the char at the top of the stack
* @h: pointer to head of stack
* @lnum: line number
*
* Return: 1
*/
int op_pchar(stack_t **h, int lnum)
{
	if (h == NULL || *h == NULL)
		printerr(16, lnum, NULL);
	if ((*h)->n < 0 || (*h)->n > 127)
		printerr(15, lnum, NULL);
	printf("%c\n", (*h)->n);

	return (1);
}
