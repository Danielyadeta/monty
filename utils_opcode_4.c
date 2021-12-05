#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom or right
 * @head: double pointer to head of linked list
 *
 * Return: pointer to the new node, otherwise NULL on failure
 */
int op_rotr(stack_t **head)
{
	stack_t *temp;
	int num;

	if (head == NULL || *head == NULL)
	{
		printf("0\n");
		return (0);
	}
	if (len_stack(*head) < 2)
		return (0);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	num = temp->n;
	while (temp->prev != NULL)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = num;
	return (1);
}
