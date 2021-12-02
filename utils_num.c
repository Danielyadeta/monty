#include "monty.h"

/**
* powrd - gives the power to 10
* @n: the power
*
* Return: the powered result
*/
int powrd(int n)
{
	int i, pwrd;

	i = 0;
	pwrd = 1;

	while (i < n && n != 0)
	{
		pwrd = pwrd * 10;
		i++;
	}

	return (pwrd);
}

/**
* iton - converts a char to int
* @c: character
*
* Return: coverted int, otherwise -1
*/
int iton(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == '2')
		return (2);
	else if (c == '3')
		return (3);
	else if (c == '4')
		return (4);
	else if (c == '5')
		return (5);
	else if (c == '6')
		return (6);
	else if (c == '7')
		return (7);
	else if (c == '8')
		return (8);
	else if (c == '9')
		return (9);
	return (-1);
}

/**
* get_push_num - gets the number to push
* @line: the input buffer
* @lnum: line number
*
* Return: the number
*/
int get_push_num(char *line, int lnum)
{
	int end, i, sum, start;

	start = 0;
	end = 0;
	i = 0;
	while (*(line + 4 + i) == ' ')
	{
		start++;
		i++;
	}
	i = 0;
	while (*(line + 4 + start + i) != ' ' &&
		*(line + 4 + start + i) != '\n' &&
		*(line + 4 + start + i) != '\0')
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
		if (*(line + 4 + start + i) < 48 || *(line + 4 + start + i) > 57)
			printerr(1, lnum, NULL);
		else
		{
			sum = sum + ((iton(*(line + 4 + start + i))) * (powrd(end - 1)));
		}
		end--;
		i++;
	}
	return (sum);
}
