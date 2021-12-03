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
