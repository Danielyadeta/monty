#include "monty.h"

/**
* check_mul - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_mul(char *line)
{
	char *str_mul;
	int i;

	i = 0;
	str_mul = "mul";
	while (i < 3)
	{
		if (*(line + i) != *(str_mul + i))
			break;
		i++;
	}
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (10);
	return (0);
}

/**
* check_mod - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_mod(char *line)
{
	char *str_mod;
	int i;

	i = 0;
	str_mod = "mod";
	while (i < 3)
	{
		if (*(line + i) != *(str_mod + i))
			break;
		i++;
	}
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (11);
	return (0);
}

/**
* check_comment - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_comment(char *line)
{
	return (*line == '#' ? 12 : 0);
}

/**
* interpret_command - interprets the op code
* @command: the opcode
* @line: the input buffer
* @head: head of stack
* @lnum: the line number
*
* Return: 0 on failiure
*/
int interpret_command(int command, char *line, stack_t **head, int lnum)
{
	if (command == 1)
		add_dnodeint(head, get_push_num(line, lnum));
	else if (command == 2)
		print_dlistint(*head);
	else if (command == 3)
		print_top(*head, lnum);
	else if (command == 4)
		op_pop(head, lnum);
	else if (command == 5)
		op_swap(*head, lnum);
	else if (command == 6)
		op_add(head, lnum);
	else if (command == 7)
		return (98);
	else if (command == 8)
		op_sub(head, lnum);
	else if (command == 9)
		op_div(head, lnum);
	else if (command == 10)
		op_mul(head, lnum);
	else if (command == 11)
		op_mod(head, lnum);
	else if (command == 12)
		return (98);
	else if (command == 13)
		op_pchar(head, lnum);
	return (0);
}

/**
* get_unknown_op - gets what the unknown op is
* @line: the input buffer
*
* Return: the unknown op
*/
char *get_unknown_op(char *line)
{
	int i;
	char *str = malloc(sizeof(char) * 50);

	if (str == NULL)
		printerr(6, 0, NULL);
	i = 0;
	while (*(line + i) != ' ' &&
		*(line + i) != '\n' && *(line + i) != '\0' &&
		*(line + i) != '\r')
	{
		*(str + i) = *(line + i);
		i++;
	}
	*(str + i) = '\0';

	return (str);
}
