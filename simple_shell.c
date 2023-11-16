#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	while (1)
	{
		ssize_t characters_read;

		printf(":) ");

		characters_read = getline(&buffer, &bufsize, stdin);

		if (characters_read == -1)
		{
			printf("\n");
			break;
		}

		buffer[characters_read - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			printf("Exiting shell\n");
			break;
		}

		if (strcmp(buffer, "env") == 0)
		{
			print_environment();
			continue;
		}

		execute_command(buffer);
	}

	free(buffer);

	return (0);
}
