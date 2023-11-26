#include "shell.h"

/**
 * tokenize_input - tokenzie input string
 * @input: input string
 * @args: double pointer
 *
 * Return: Always 0 (Success)
 */

void tokenize_input(const char *input, char **args)
{
	char *input_copy, *token_start, *token_end;
	int i, args_count, input_len, token_len;

	for (input_len = 0; input[input_len] != '\0'; input_len++)
		;
	input_copy = malloc(input_len + 1);
	if (input_copy == NULL)
	{
		output("Error: Memory allocation failed\n");
		return;
	}
	for (i = 0; i <= input_len; i++)
		input_copy[i] = input[i];
	args_count = 0;
	token_start = input_copy;
	while (*token_start != '\0')
	{
		while (*token_start == ' ' || *token_start == '\n')
			token_start++;
		token_end = token_start;
		while (*token_end != ' ' && *token_end != '\n' && *token_end != '\0')
			token_end++;
		token_len = token_end - token_start;
		args[args_count] = malloc(token_len + 1);
		if (args[args_count] == NULL)
		{
			output("Error: Memory allocation failed\n");
			for (i = 0; i < args_count; ++i)
				free(args[i]);
			free(input_copy);
			return;
		}
		for (i = 0; i < token_len; i++)
			args[args_count][i] = token_start[i];
		args[args_count][token_len] = '\0';
		args_count++;
		token_start = token_end;
	}
	args[args_count] = NULL;
	free(input_copy);
}
