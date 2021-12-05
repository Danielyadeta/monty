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

	if (len_stack(*h) < 2)
		printerr(14, lnum, NULL);
	a = op_pop(h, lnum);
	if (a == 0)
		printerr(12, lnum, NULL);

	(*h)->n = (*h)->n % a;

	return (1);
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
	if ((*h)->n < 32 || (*h)->n > 126)
		printerr(15, lnum, NULL);
	printf("%c\n", (*h)->n);

	return (1);
}

/**
* op_pstr - prints the string starting at the top of the stack
* @h: pointer to head of stack
*
* Return: 1
*/
int op_pstr(stack_t **h)
{
	stack_t *current;

	current = *h;
	if (h == NULL || *h == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	while (current->n != '0' && current != NULL &&
		(current->n > 31 && current->n < 127))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
	return (1);
}

/**
 * op_push_queue - add a new node at the end of a stack list
 * @head: double pointer to the head of a list
 * @n: value to add to new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *op_push_queue(stack_t **head, const int n)
{
	stack_t *temp, *new;

	new = malloc(sizeof(stack_t));
	if (head == NULL || new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}

/**
 * op_rotl - rotates the stack to the top or left
 * @head: double pointer to head of linked list
 *
 * Return: pointer to the new node, otherwise NULL on failure
 */
int op_rotl(stack_t **head)
{
	stack_t *temp;
	int num;

	if (head == NULL || *head == NULL)
		printerr(1, 0, NULL);
	if (len_stack(*head) < 2)
		return (0);
	temp = *head;
	num = temp->n;
	while (temp->next != NULL)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = num;
	return (1);
}
