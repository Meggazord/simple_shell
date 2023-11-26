#include "shell.h"

/**
 * get_program_name - gets program name
 *@argv: the name to be captured
 *
 * Return: Nothing
 */

char *get_program_name(char *argv[])
{
	char *program_name, *ptr;

	program_name = argv[0];
	ptr = argv[0];

	while (*ptr != '\0')
	{
		if (*ptr == '/')
		{
			program_name = ptr + 1;
		}
		ptr++;
	}

	return (program_name);
}
