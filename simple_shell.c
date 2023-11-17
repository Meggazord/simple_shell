#include "shell.h"
<<<<<<< HEAD

=======
>>>>>>> 8a29a95046f15b69dad5c0fb0939a6a459ddea3a
#define BUFFER_SIZE 1024

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 8a29a95046f15b69dad5c0fb0939a6a459ddea3a

    free(buffer);

    return (0);
}
