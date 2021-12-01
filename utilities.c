#include "monty.h"

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

void printerr(char *str)
{
	printf("%s\n", str);
	exit(1);
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

int check_command(char *line)
{
	int command;

	command = 0;
	command = check_push(line);
	if (command == 0)
		command = check_pall(line);
        if (command == 0)
                command = check_pint(line);
	if (command == 0)
		command = check_pop(line);
	if (command == 0)
		command = check_swap(line);
	if (command == 0)
		command = check_add(line);
	if (command == 0)
		command = check_nop(line);
        if (command == 0)
                command = check_sub(line);
	return (command);
}

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
