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
