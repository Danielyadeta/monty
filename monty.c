#include "monty.h"

/**
* main - starting point for monty read
* @argc: argument count
* @argv: argument vector
* @env: environment
*
* Return: EXIT_SUCCESS on success, otherwise EXIT_FAILIURE
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char *line;
	size_t len;
/*	ssize_t read; */
	stack_t *head;
	int lnum, sum, end, i, start, command;

	if (argc != 2)
		printerr("USAGE: monty file");

	i = 0;
	head = NULL;
	lnum = 1;
	line = NULL;
	len = 0;
	fp = fopen(argv[1], "r");

	if (fp == NULL)
		printerr("Error: Can't open file <file>");

	while (getline(&line, &len, fp) != -1)
	{
/*		process_monty(line, head, lnum); */
		start = 0;
		i = 0;
		while (*(line + start) == ' ')
			start++;

		command = check_command(line + start);
		if (command == 0)
		{
			printf("L%d %s\n", lnum, "Not command");
			exit(1);
		}
		end = 0;

		while (*(line + start + 5 + i) != ' ' && *(line + start + 5 + i) != '\n' && *(line + start + 5 + i) != '\0')
		{
			end++;
			i++;
		}
		
		i = 0;
		if (command == 1)
		{
			sum = 0;
			while (end > 0)
			{
				if (*(line + start + 5 + i) < 48 || *(line + start + 5 + i) > 57)
					printerr("not number");
				else
				{
					sum = sum + ((iton(*(line + start + 5 + i))) * (powrd(end - 1)));
				}
				end--;
				i++;
			}
			add_dnodeint(&head, sum);
		}
		else if (command == 2)
			print_dlistint(head);
		else if (command == 3)
			print_top(head);
		else if (command == 4)
			op_pop(&head);
		else if (command == 5)
			op_swap(head);
		else if (command == 6)
			op_add(&head);
		else if (command == 7)
			continue;
                else if (command == 8)
                        op_sub(&head);
                else if (command == 9)
                        op_div(&head);
		lnum++;
	}

	fclose(fp);
	if (line)
		free(line);

	return(EXIT_SUCCESS);
}
