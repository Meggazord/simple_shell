#include "shell.h"

/**
 * handle_path - path handling funciton
 * @args: path input
 *
 * Return: Nothing
 */

void handle_path(char **args)
{
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
		char *path_env = getenv("PATH");

		if (path_env != NULL)
		{
			char *path = strtok(path_env, ":");

			while (path != NULL)
			{
				char command_path[MAX_INPUT];

				strcpy(command_path, path);
                strcat(command_path, "/");
                strcat(command_path, args[0]);

				if (access(command_path, X_OK) == 0)
				{
					execve(command_path, args, environ);
					output("Execution error for command: ");
					output(args[0]);
					output("\n");
					perror("Error");
					exit(EXIT_FAILURE);
				}

				path = strtok(NULL, ":");
			}
		}
	}
}
