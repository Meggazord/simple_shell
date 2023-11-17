#include "shell.h"

/**
 * execute_command - check user input and execute if applicable
 * @args: the input from the user to be handled
 *
 * Return: Nothing
 */

void execute_command(char **args)
{
	char *program_name;
	char *error_msg;

	program_name = get_program_name(args);
	error_msg = ": not found\n";

	if (execve(args[0], args, environ) == -1)
	{
		write(STDERR_FILENO, program_name, strlen(program_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		_exit(EXIT_FAILURE);
	}
}


/**
 * exit_shell - exits the shell
 *
 * Return: Nothing
 */

void exit_shell(void)
{
	write(STDOUT_FILENO, "Exiting the shell.\n", 19);
	_exit(EXIT_SUCCESS);
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
 * @argv: the number of argv
 *
 * Return: Nothing
 */

void execute(const char *input, char *argv[])
{
	pid_t child_pid;
	char *program_name;

	if (strcmp(input, "exit") == 0)
	{
		exit_shell();
	}

	if (argv[0] == NULL)
	{
		write(STDERR_FILENO, "Error: Null argv[0].\n", 21);
		_exit(EXIT_FAILURE);
	}

	program_name = get_program_name(argv);

	child_pid = fork();

	if (child_pid == -1)
	{
		write(STDERR_FILENO, program_name, strlen(program_name));
		write(STDERR_FILENO, ": Forking error.\n", 17);
		_exit(EXIT_FAILURE);
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
