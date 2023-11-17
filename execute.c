#include "shell.h"

/**
 * execute_command - check user input and execute if applicable
 * @args: the input from the user to be handled
 *
 * Return: Nothing
 */

void execute_command(char **args)
{
	if (execve(args[0], args, environ) == -1)
	{
		output("Execution error for command: ");
		output(args[0]);
		output("\n");
		perror("Error");
		exit(EXIT_FAILURE);
	}
}


/**
 * exit_shell - exits the shell
 *
 * Return: Nothing
 */

void exit_shell(void)
{
	output("Exiting the shell.\n");
	exit(EXIT_SUCCESS);
}

/**
 * execute_child - executes the command in the child process
 * @input: the input from the user to be handled
 *
 * Return: Nothing
 */

void execute_child(const char *input)
{
	char **args;
	int i;
	int args_count;
	char *token;

	args = malloc((MAX_TOKENS + 1) * sizeof(char *));

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

	handle_path(args);
	execute_command(args);

	for (i = 0; i < args_count; ++i)
	{
		free(args[i]);
	}
	free(args);

	exit(EXIT_FAILURE);
}

/**
 * execute - check user input and execute if applicable
 * @input: the input from the user to be handled
 *
 * Return: Nothing
 */

void execute(const char *input)
{
	pid_t child_pid;

	if (strcmp(input, "exit") == 0)
	{
		exit_shell();
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		output("Forking error.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execute_child(input);
	}
	else
	{
		wait(NULL);
	}
}
