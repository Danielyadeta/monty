#include "monty.h"

/**
* check_command - identifies what the command is
* @line: the input buffer
*
* Return: non-zero if found, otherwise 0
*/
int check_command(char *line)
{
	int i, command;
	int (*chkrs[])(char*) = {check_push, check_pall,
		check_pint, check_pop, check_swap, 
		check_add, check_nop, check_sub, check_div,
		check_mul, check_mod, check_comment};

	i = 0;
	command = 0;
	while (command == 0 && i < 12)
	{
		command = chkrs[i](line);
		i++;
	}
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
	str_push = "push ";
	while (i < 5)
	{
		if (*(line + i) != *(str_push + i))
			break;
		i++;
	}
	return (i == 5 ? 1 : 0);
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
	return (i == 4 ? 2 : 0);
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
	return (i == 4 ? 3 : 0);
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
	return (i == 3 ? 4 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_swap(char *line)
{
	char *str_swap;
	int i;

	i = 0;
	str_swap = "swap";
	while (i < 4)
	{
		if (*(line + i) != *(str_swap + i))
			break;
		i++;
	}
	return (i == 4 ? 5 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_add(char *line)
{
	char *str_add;
	int i;

	i = 0;
	str_add = "add";
	while (i < 3)
	{
		if (*(line + i) != *(str_add + i))
			break;
		i++;
	}
	return (i == 3 ? 6 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_nop(char *line)
{
	char *str_nop;
	int i;

	i = 0;
	str_nop = "nop";
	while (i < 3)
	{
		if (*(line + i) != *(str_nop + i))
			break;
		i++;
	}
	return (i == 3 ? 7 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_sub(char *line)
{
	char *str_sub;
	int i;

	i = 0;
	str_sub = "sub";
	while (i < 3)
	{
		if (*(line + i) != *(str_sub + i))
			break;
		i++;
	}
	return (i == 3 ? 8 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_div(char *line)
{
	char *str_div;
	int i;

	i = 0;
	str_div = "div";
	while (i < 3)
	{
		if (*(line + i) != *(str_div + i))
			break;
		i++;
	}
	return (i == 3 ? 9 : 0);
}

/**
* check_push - checks if the command is push
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
	return (i == 3 ? 10 : 0);
}

/**
* check_push - checks if the command is push
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
	return (i == 3 ? 11 : 0);
}

/**
* check_push - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_comment(char *line)
{
	return (*line == '#' ? 12 : 0);
}
