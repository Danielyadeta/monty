#include "monty.h"

/**
 * add_dnodeint - add a new node at the beginning of a stack list
 * @head: double pointer to head of linked list
 * @n: value to the new node
 *
 * Return: pointer to the new node, otherwise NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (head == NULL || new == NULL)
		return (NULL);

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

	if (h == NULL)
		return (0);
	count = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}

/**
* print_top - prints the int at top of stack
* @h: head of the stack
* @lnum: the line number
*
* Return: 1
*/
size_t print_top(const stack_t *h, int lnum)
{
	if (h == NULL)
		printerr(2, lnum, NULL);
	printf("%d\n", h->n);
	return (1);
}

/**
* op_pop - pops the stack
* @head: head of the stack
* @lnum: line number
*
* Return: the value of the popped node
*/
int op_pop(stack_t **head, int lnum)
{
	stack_t *current;
	int pop_val;

	if (head == NULL || *head == NULL)
		printerr(7, lnum, NULL);
	current = *head;
	pop_val = current->n;
	*head = current->next;
	if (current->next != NULL)
	{
		current->next->prev = NULL;
	}
	free(current);
	return (pop_val);
}

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to a dlistint_t list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const stack_t *h)
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
