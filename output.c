#include "shell.h"

/**
 * output - output for the simple shell program
 *@result: the output to be returned to use
 *
 * Return: Nothing
 */

void output(const char *result)
{
	write(STDOUT_FILENO, result, strlen(result));
}
