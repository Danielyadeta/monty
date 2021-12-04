#include "monty.h"

/**
* check_swap - checks if the command is push
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
	if (i == 4 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (5);
	return (0);
}

/**
* check_add - checks if the command is push
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
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (6);
	return (0);
}

/**
* check_nop - checks if the command is push
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
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (7);
	return (0);
}

/**
* check_sub - checks if the command is push
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
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (8);
	return (0);
}

/**
* check_div - checks if the command is push
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
	if (i == 3 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (9);
	return (0);
}
