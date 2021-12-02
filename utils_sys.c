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
	free(str);
	exit(EXIT_FAILURE);
}
