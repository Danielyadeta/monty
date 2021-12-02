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
	free(str);
	exit(EXIT_FAILURE);
}
