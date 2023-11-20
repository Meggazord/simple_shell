#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: arguments
 * @argv: arguments array
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char input[MAX_INPUT];

	while (1)
	{
		get_input(input, sizeof(input));
		execute(input);
	}

	return (0);
}

