#include "shell.h"

/**
 * get_program_name - gets program name
 *@argv: the name to be captured
 *
 * Return: Nothing
 */

char *get_program_name(char *argv[])
{
	char *program_name;

	program_name = strrchr(argv[0], '/');

	if (program_name == NULL)
	{
		return (argv[0]);
	}
	return (program_name + 1);
}
