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
    char *input_copy, *token;
    int i, args_count;

    input_copy = strdup(input);

    if (input_copy == NULL)
    {
        output("Error: Memory allocation failed\n");
        return;
    }

    args_count = 0;
    token = strtok(input_copy, " \n");

    while (token != NULL)
    {
        args[args_count] = strdup(token);

        if (args[args_count] == NULL)
        {
            output("Error: Memory allocation failed\n");
            for (i = 0; i < args_count; ++i)
            {
                free(args[i]);
            }
            free(input_copy);
            return;
        }

        args_count++;
        token = strtok(NULL, " \n");
    }

    args[args_count] = NULL;

    free(input_copy);
}
