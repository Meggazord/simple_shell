#include "shell.h"

/**
 * output - output for the simple shell program
 *@output_text: the output to be returned to use
 *
 * Return: Nothing
 */

void output(const char *output_text)
{
	write(STDOUT_FILENO, output_text, strlen(output_text));
}
