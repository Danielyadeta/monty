#include "monty.h"

/**
* check_rotl - checks if the command is rotl
* @line: the input buffer
*
* Return: 1 if found, otherwise 0
*/
int check_rotl(char *line)
{
	char *str_rotl;
	int i;

	i = 0;
	str_rotl = "rotl";
	while (i < 4)
	{
		if (*(line + i) != *(str_rotl + i))
			break;
		i++;
	}
	if (i == 4 && (*(line + i) == ' ' ||
		*(line + i) == '\n' ||
		*(line + i) == '\0' ||
		*(line + i) == '\r'))
		return (18);
	return (0);
}
