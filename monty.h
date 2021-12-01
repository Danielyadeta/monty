#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
int powrd(int n);
void printerr(char *str);
int iton(char c);
int check_command(char *line);
int check_push(char *line);
int check_pall(char *line);
size_t print_top(const stack_t *h);
int check_pint(char *line);
int check_pop(char *line);
int op_pop(stack_t **head);
int check_swap(char *line);
size_t dlistint_len(const stack_t *h);
int op_swap(stack_t *h);
int op_add(stack_t **h);
int check_add(char *line);
int check_nop(char *line);
int op_sub(stack_t **h);
int check_sub(char *line);

#endif /* MONTY_H */
