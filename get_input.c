#include "shell.h"

/**
 * get_input - capture user input
 * @input: user input
 * @size: input size
 *
 * Return: Nothing
 */
void get_input(char *input, size_t size)
{
	ssize_t read_chars;

	read_chars = read(STDIN_FILENO, input, size);
	if (read_chars == -1)
	{
		output("Error reading input.\n");
		exit(EXIT_FAILURE);
	}

	if (read_chars == 0 || (read_chars == 1 && input[0] == '\n'))
	{
		prompt();
		exit(EXIT_SUCCESS);
	}

	input[read_chars - 1] = '\0';
}
