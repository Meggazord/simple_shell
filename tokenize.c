#include "shell.h"

/**
 * tokenize_input - tokenize input string
 * @input: input string
 * @args: double pointer
 *
 * Return: Always 0 (Success)
 */

void tokenize_input(const char *input, char **args)
{
	char *input_copy, *token;
	int args_count, i;

	args_count = 0;

	input_copy = malloc((_strlen(input) + 1) * sizeof(char));

	if (input_copy == NULL)
	{
		output("Error: Memory allocation failed\n");
		return;
	}

	_strcpy(input_copy, input);

	token = strtok(input_copy, " \n");

	while (token != NULL)
	{
		args[args_count] = malloc((_strlen(token) + 1) * sizeof(char));
		if (args[args_count] == NULL)
		{
			output("Error: Memory allocation failed\n");
			for (i = 0; i < args_count; ++i)
				free(args[i]);
			free(input_copy);
			return;
		}
		_strcpy(args[args_count], token);
		args_count++;
		token = strtok(NULL, " \n");
	}

	args[args_count] = NULL;
	free(input_copy);
}
