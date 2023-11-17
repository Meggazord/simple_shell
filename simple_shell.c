#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
    char input[MAX_INPUT];

    (void)argc;

    while (1)
    {
        prompt();
        get_input(input, sizeof(input));
        execute(input, argv);
    }

    return (0);
}

