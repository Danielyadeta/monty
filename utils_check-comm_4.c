#include "monty.h"

/**
* check_pchar - checks if the command is pchar
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_pchar(char *line)
{
	char *str_pchar;
	int i;

	i = 0;
	str_pchar = "pchar";
	while (i < 5)
	{
		if (*(line + i) != *(str_pchar + i))
			break;
		i++;
	}
	if (i == 5 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (13);
	return (0);
}

/**
* check_empty - checks if the command is push
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_empty(char *line)
{
	int i;

	i = 0;
	while (*(line + i) != '\n' && *(line + i) != '\0')
	{
		if (*(line + i) != ' ')
			break;
		i++;
	}
	if (*(line + i) == '\n' || *(line + i) == '\0')
		return (14);
	return (0);
}

/**
* check_pstr - checks if the command is pstr
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_pstr(char *line)
{
	char *str_pstr;
	int i;

	i = 0;
	str_pstr = "pstr";
	while (i < 4)
	{
		if (*(line + i) != *(str_pstr + i))
			break;
		i++;
	}
	if (i == 4 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (15);
	return (0);
}

/**
* check_queue - checks if the command is queue
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_queue(char *line)
{
	char *str_queue;
	int i;

	i = 0;
	str_queue = "queue";
	while (i < 5)
	{
		if (*(line + i) != *(str_queue + i))
			break;
		i++;
	}
	if (i == 5 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (16);
	return (0);
}

/**
* check_stack - checks if the command is stack
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_stack(char *line)
{
	char *str_stack;
	int i;

	i = 0;
	str_stack = "stack";
	while (i < 5)
	{
		if (*(line + i) != *(str_stack + i))
			break;
		i++;
	}
	if (i == 5 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (17);
	return (0);
}
