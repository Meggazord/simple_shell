#include "shell.h"

/**
 * execute_command - Execute a command received as input
 * 
 * @buffer: Input command to be executed
 */
void execute_command(char *buffer)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char *args[100];
		int i = 0;

		char *token = strtok(buffer, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		if (access(args[0], X_OK) == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = getenv("PATH");
			char *full_path;

			char *token = strtok(path, ":");
			while (token != NULL)
			{
				full_path = malloc(strlen(token) + strlen(args[0]) + 2);
				if (full_path == NULL)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}

				sprintf(full_path, "%s/%s", token, args[0]);

				if (access(full_path, X_OK) == 0)
				{
					if (execve(full_path, args, NULL) == -1)
					{
						perror("execve");
						exit(EXIT_FAILURE);
					}
				}

				free(full_path);
				token = strtok(NULL, ":");
			}

			printf("%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
