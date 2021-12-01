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
	return (i == 3 ? 10 : 0);
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
	return (i == 3 ? 11 : 0);
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
