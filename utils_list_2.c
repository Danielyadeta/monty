#include "monty.h"

/**
* op_swap -  swaps the top two elements of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_swap(stack_t *h, int lnum)
{
	int s;

	if (dlistint_len(h) < 2)
		printerr(8, lnum, NULL);
	s = h->n;
	h->n = h->next->n;
	h->next->n = s;

	return (1);
}

/**
* op_add -  swaps the top two elements of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_add(stack_t **h, int lnum)
{
	int a;

	if (dlistint_len(*h) < 2)
		printerr(9, lnum, NULL);
	a = op_pop(h, lnum);
	(*h)->n = (*h)->n + a;

	return (1);
}

/**
* op_sub -  swaps the top two elements of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_sub(stack_t **h, int lnum)
{
	int a;

	if (dlistint_len(*h) < 2)
		printerr(10, lnum, NULL);
	a = op_pop(h, lnum);
	(*h)->n = (*h)->n - a;

	return (1);
}

/**
* op_div -  swaps the top two elements of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_div(stack_t **h, int lnum)
{
	int a;

	if (dlistint_len(*h) < 2)
		printerr(11, lnum, NULL);
	a = op_pop(h, lnum);
	if (a == 0)
		printerr(12, lnum, NULL);

	(*h)->n = (*h)->n / a;

	return (1);
}

/**
* op_mul -  swaps the top two elements of the stack
* @h: head of the stack
* @lnum: line number
*
* Return: 1
*/
int op_mul(stack_t **h, int lnum)
{
	int a;

	if (dlistint_len(*h) < 2)
		printerr(13, lnum, NULL);
	a = op_pop(h, lnum);
	(*h)->n = (*h)->n * a;

	return (1);
}
