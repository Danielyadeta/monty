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
