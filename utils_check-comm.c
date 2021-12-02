#include "monty.h"

/**
* check_command - identifies what the command is
* @line: the input buffer
* @lnum: the line number
*
* Return: non-zero if found, otherwise 0
*/
int check_command(char *line, int lnum)
{
	int i, command;

	int (*chkrs[])(char *) = {check_push, check_pall,
		check_pint, check_pop, check_swap,
		check_add, check_nop, check_sub, check_div,
		check_mul, check_mod, check_comment, check_pchar};

	i = 0;
	command = 0;
	while (command == 0 && i < 13)
	{
		command = chkrs[i](line);
		i++;
	}
	if (command == 0)
		printerr(3, lnum, get_unknown_op(line));
	return (command);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_push(char *line)
{
	char *str_push;
	int i;

	i = 0;
	str_push = "push";
	while (i < 4)
	{
		if (*(line + i) != *(str_push + i))
			break;
		i++;
	}
	return (i == 4 ? 1 : 0);
}

/**
* check_pall - checks if the command is push
* @line: the input buffer
*
* Return: 2 if found, otherwise 0
*/
int check_pall(char *line)
{
	char *str_pall;
	int i;

	i = 0;
	str_pall = "pall";
	while (i < 4)
	{
		if (*(line + i) != *(str_pall + i))
			break;
		i++;
	}
	if (i == 4 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (2);
	return (0);
}

/**
* check_pint - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_pint(char *line)
{
	char *str_pint;
	int i;

	i = 0;
	str_pint = "pint";
	while (i < 4)
	{
		if (*(line + i) != *(str_pint + i))
			break;
		i++;
	}
	if (i == 4 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (3);
	return (0);
}

/**
* check_pop - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_pop(char *line)
{
	char *str_pop;
	int i;

	i = 0;
	str_pop = "pop";
	while (i < 3)
	{
		if (*(line + i) != *(str_pop + i))
			break;
		i++;
	}
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (4);
	return (0);
}
