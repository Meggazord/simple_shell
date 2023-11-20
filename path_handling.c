#include "shell.h"

/**
 * handle_path - path handling funciton
 * @args: path input
 *
 * Return: Nothing
 */

void handle_path(char **args)
{
	char *path_env, *path, *token;

    if (access(args[0], X_OK) == 0)
    {
        execve(args[0], args, environ);
        output("Execution error for command: ");
        output(args[0]);
        output("\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }

    else
    {
        path_env = _getenv("PATH");

        if (path_env != NULL)
        {
            path = path_env;

            while ((token = strtok(path, ":")) != NULL)
            {
                char command_path[MAX_INPUT];
                _strcpy(command_path, token);
                _strcat(command_path, "/");
                _strcat(command_path, args[0]);

                if (access(command_path, X_OK) == 0)
                {
                    execve(command_path, args, environ);
                    output("Execution error for command: ");
                    output(args[0]);
                    output("\n");
                    perror("Error");
                    exit(EXIT_FAILURE);
                }

                path = NULL;
            }
        }
    }
}
