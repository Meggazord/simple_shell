#include "shell.h"

int main(void)
{
    char *line = NULL; // Initialize to NULL
    char **args = NULL;

    size_t size = MAX_INPUT;

    while (1)
    {
        printf(":) ");
        if (getline(&line, &size, stdin) == -1)
        {
            free(line); // Free memory before exiting
            printf("\n");
            exit(EXIT_SUCCESS);
        }

        args = tokenize(line);

        if (args != NULL && args[0] != NULL)
            execute(args);

        free(args); // Free the tokenized arguments
    }

    return (0);
}
