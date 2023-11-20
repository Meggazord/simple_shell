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
 * @size: input size
 *
 * Return: Nothing
 */

void get_input(char *input, size_t size)
{
	size_t read_chars;

	prompt();

	read_chars = getline(&input, &size, stdin);

	if (read_chars == (size_t)-1)
	{
		output("Error reading input.\n");
		free(input);
		exit(EXIT_FAILURE);
	}

	if (read_chars == 1 || input[0] == '\n') 
	{
		return;
	}

	input[read_chars - 1] = '\0';
}
