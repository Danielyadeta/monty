#include "monty.h"

/**
* printerr - prints error and exits
* @errnum: the error number
* @lnum: the line number
* @str: the unknown op
*
* Return: Always Void
*/
void printerr(int errnum, int lnum, char *str)
{
	char *errone = ": usage: push integer";
	char *errtwo = ": can't pint, stack empty";
	char *errthree = ": unknown instruction ";
	char *errfour = "USAGE: monty file";
	char *errfive = "Error: Can't open file ";
	char *errsix = "Error: malloc failed";
	char *errseven = ": can't pop an empty stack";
	char *erreight = ": can't swap, stack too short";
	char *errnine = ": can't add, stack too short";
	char *errten = ": can't sub, stack too short";
	char *erreleven = ": can't div, stack too short";
	char *errtwelve = ": division by zero";
	char *errthirteen = ": can't mul, stack too short";
	char *errfourteen = ": can't mod, stack too short";
	char *errfifteen = ": can't pchar, value out of range";
	char *errsixteen = ": can't pchar, stack empty";

	if (errnum == 1)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errone);
	else if (errnum == 2)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errtwo);
	else if (errnum == 3)
		dprintf(STDERR_FILENO, "L%d%s%s\n", lnum, errthree, str);
	else if (errnum == 4)
		dprintf(STDERR_FILENO, "%s\n", errfour);
	else if (errnum == 5)
		dprintf(STDERR_FILENO, "%s%s\n", errfive, str);
	else if (errnum == 6)
		dprintf(STDERR_FILENO, "%s\n", errsix);
	else if (errnum == 7)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errseven);
	else if (errnum == 8)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, erreight);
	else if (errnum == 9)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errnine);
	else if (errnum == 10)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errten);
	else if (errnum == 11)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, erreleven);
	else if (errnum == 12)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errtwelve);
	else if (errnum == 13)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errthirteen);
	else if (errnum == 14)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errfourteen);
	else if (errnum == 15)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errfifteen);
	else if (errnum == 16)
		dprintf(STDERR_FILENO, "L%d%s\n", lnum, errsixteen);
	if (str && errnum != 5)
		free(str);
	exit(EXIT_FAILURE);
}

/**
* interpret_command - interprets the op code
* @command: the opcode
* @line: the input buffer
* @head: head of stack
* @lnum: the line number
*
* Return: 0 on failiure
*/
int interpret_command(int command, char *line, stack_t **head, int lnum)
{
	extern int stk_que;

	if (command == 1)
		stk_que == 0 ?
		op_push(head, get_push_num(line, lnum)) :
		op_push_queue(head, get_push_num(line, lnum));
	else if (command == 2)
		op_pall(*head);
	else if (command == 3)
		op_pint(*head, lnum);
	else if (command == 4)
		op_pop(head, lnum);
	else if (command == 5)
		op_swap(*head, lnum);
	else if (command == 6)
		op_add(head, lnum);
	else if (command == 7)
		return (98);
	else if (command == 8)
		op_sub(head, lnum);
	else if (command == 9)
		op_div(head, lnum);
	else if (command == 10)
		op_mul(head, lnum);
	else if (command == 11)
		op_mod(head, lnum);
	else if (command == 12)
		return (98);
	else if (command == 13)
		op_pchar(head, lnum);
	else if (command == 14)
		return (98);
	else if (command == 15)
		op_pstr(head);
	else  if (command == 16)
		stk_que = 1;
	else if (command == 17)
		stk_que = 0;
	return (0);
}

/**
* get_unknown_op - gets what the unknown op is
* @line: the input buffer
*
* Return: the unknown op
*/
char *get_unknown_op(char *line)
{
	int i;
	char *str = malloc(sizeof(char) * 50);

	if (str == NULL)
		printerr(6, 0, NULL);
	i = 0;
	while (*(line + i) != ' ' &&
		*(line + i) != '\n' && *(line + i) != '\0' &&
		*(line + i) != '\r')
	{
		*(str + i) = *(line + i);
		i++;
	}
	*(str + i) = '\0';

	return (str);
}
