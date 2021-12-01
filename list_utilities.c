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

	count = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}

size_t print_top(const stack_t *h)
{
	printf("%d\n", h->n);
	return (1);
}

int op_pop(stack_t **head)
{
	stack_t *current;
	int pop_val;

	if (head == NULL || *head == NULL)
		printerr("Empty stack");
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

int op_swap(stack_t *h)
{
	int s;

	if (dlistint_len(h) < 2)
		printerr("Less than two");
	s = h->n;
	h->n = h->next->n;
	h->next->n = s;

	return (1);
}
/*
int op_add(stack_t **h)
{
	int a;
	int b;
	int c;

	a = op_pop(h);
	b = op_pop(h);
	c = a + b;

	add_dnodeint(h, c);
	return (1);
}
*/
int op_add(stack_t **h)
{
        int a;
 
        a = op_pop(h);
	(*h)->n = (*h)->n + a;

	return (1);
}

int op_sub(stack_t **h)
{
        int a;

        a = op_pop(h);
        (*h)->n = (*h)->n - a;

        return (1);
}

int op_div(stack_t **h)
{
        int a;

	a = op_pop(h);
	if (a == 0)
		printerr("number is 0");

        (*h)->n = (*h)->n / a;

        return (1);
}

int op_mul(stack_t **h)
{
        int a;

        a = op_pop(h);
        (*h)->n = (*h)->n * a;

        return (1);
}

int op_mod(stack_t **h)
{
        int a;

        a = op_pop(h);
        if (a == 0)
                printerr("number is 0");

        (*h)->n = (*h)->n % a;

        return (1);
}
