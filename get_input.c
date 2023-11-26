#include "shell.h"

/**
 * prompt - prompt user to start process
 *
 * Return: Nothing
 */

void prompt(void)
{
	output("$ ");
}

/**
 * get_input - capture user input
 * @input: user input
 * @max_size: input size
 *
 * Return: Nothing
 */

void get_input(char *input, size_t max_size)
{
	ssize_t read_chars, i;

	prompt();

	read_chars = read(STDIN_FILENO, input, max_size);

	if (read_chars == -1)
	{
		output("Error reading input.\n");
		exit(EXIT_FAILURE);
	}

	input[read_chars] = '\0';

	for (i = 0; i < read_chars; ++i)
	{
		if (input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
	}
}

