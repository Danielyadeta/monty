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
