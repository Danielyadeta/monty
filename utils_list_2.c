#include "monty.h"

/**
* op_swap -  swaps the top two elements of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_swap(stack_t *h)
{
	int s;

	if (dlistint_len(h) < 2)
		printerr(4, 0, NULL);
	s = h->n;
	h->n = h->next->n;
	h->next->n = s;

	return (1);
}

/**
* op_add -  swaps the top two elements of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_add(stack_t **h, int lnum)
{
	int a;

	a = op_pop(h, lnum);
	(*h)->n = (*h)->n + a;

	return (1);
}

/**
* op_sub -  swaps the top two elements of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_sub(stack_t **h, int lnum)
{
	int a;

	a = op_pop(h, lnum);
	(*h)->n = (*h)->n - a;

	return (1);
}

/**
* op_div -  swaps the top two elements of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_div(stack_t **h, int lnum)
{
	int a;

	a = op_pop(h, lnum);
	if (a == 0)
		printerr(4, 0, NULL);

	(*h)->n = (*h)->n / a;

	return (1);
}

/**
* op_mul -  swaps the top two elements of the stack
* @h: head of the stack
*
* Return: 1
*/
int op_mul(stack_t **h, int lnum)
{
	int a;

	a = op_pop(h, lnum);
	(*h)->n = (*h)->n * a;

	return (1);
}
