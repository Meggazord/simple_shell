#include "shell.h"

/**
 * execute - check user input and execute if applicable
 * @input: the input from the user to be handled
 *
 * Return: Nothing
 */
void execute(const char *input)
{
    int i;
    int args_count;
    char *token;
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        output("Forking error.\n");
        exit(EXIT_FAILURE);
    }

    else if (child_pid == 0)
    {
        char **args = malloc((MAX_TOKENS + 1) * sizeof(char *));
        if (args == NULL)
        {
            output("Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        args_count = 0;

        token = strtok((char *)input, " ");

        while (token != NULL && args_count < MAX_TOKENS)
        {
            args[args_count++] = strdup(token);
            token = strtok(NULL, " ");
        }

        args[args_count] = NULL;

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
                    snprintf(command_path, sizeof(command_path), "%s/%s", path, args[0]);

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

            output("Command not found: ");
            output(args[0]);
            output("\n");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < args_count; ++i)
        {
            free(args[i]);
        }
        free(args);
    }
    else
    {
        wait(NULL);
    }
}
