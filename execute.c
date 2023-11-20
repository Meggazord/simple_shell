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
		output(program_name);
        output(": 1: ");
        output(args[0]);
        output(error_msg);
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
	output("Exiting the shell.\n");
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
    char *args[MAX_TOKENS + 1];
    int i;
    
    tokenize_input(input, args);
    handle_path(args);
    execute_command(args);

    for (i = 0; args[i] != NULL; ++i)
    {
        free(args[i]);
    }

    exit(EXIT_FAILURE);
}


/**
 * execute - check user input and execute if applicable
 * @input: the input from the user to be handled
 * @argv: the number of argv
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
