#include "monty.h"

/**
* main - starting point for monty read
* @argc: argument count
* @argv: argument vector
*
* Return: EXIT_SUCCESS on success, otherwise EXIT_FAILIURE
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char *line;
	size_t len;
	stack_t *head;
	int lnum, command, start, ret;

	if (argc != 2)
		printerr(4, 0, NULL);
	head = NULL;
	lnum = 1;
	line = NULL;
	len = 0;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		printerr(5, 0, argv[1]);
	while (getline(&line, &len, fp) != -1)
	{
		start = 0;
		while (*(line + start) == ' ')
			start++;

		command = check_command(line + start, lnum);
		ret = interpret_command(command, line + start, &head, lnum);
		if (ret == 98)
		{
			lnum++;
			continue;
		}
		lnum++;
	}
	fclose(fp);
	if (line)
		free(line);
	free_dlistint(head);
	return (EXIT_SUCCESS);
}
