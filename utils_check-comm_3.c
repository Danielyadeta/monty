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
		add_dnodeint(head, get_push_num(line));
	else if (command == 2)
		print_dlistint(*head);
	else if (command == 3)
		print_top(*head, lnum);
	else if (command == 4)
		op_pop(head);
	else if (command == 5)
		op_swap(*head);
	else if (command == 6)
		op_add(head);
	else if (command == 7)
		return (98);
	else if (command == 8)
		op_sub(head);
	else if (command == 9)
		op_div(head);
	else if (command == 10)
		op_mul(head);
	else if (command == 11)
		op_mod(head);
	else if (command == 12)
		return (98);

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

/**
* get_push_num - gets the number to push
* @line: the input buffer
*
* Return: the number
*/
int get_push_num(char *line)
{
	int end, i, sum;

	end = 0;
	i = 0;
	while (*(line + 5 + i) != ' ' &&
		*(line + 5 + i) != '\n' &&
		*(line + 5 + i) != '\0')
	{
		end++;
		i++;
	}
	if (end == 0)
		printerr(1, lnum, NULL);
	i = 0;
	sum = 0;
	while (end > 0)
	{
		if (*(line + 5 + i) < 48 || *(line + 5 + i) > 57)
			printerr(1, lnum, NULL);
		else
		{
			sum = sum + ((iton(*(line + 5 + i))) * (powrd(end - 1)));
		}
		end--;
		i++;
	}
	return (sum);
}
