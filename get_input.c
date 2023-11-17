#include "shell.h"

void get_input(char *input, size_t size) 
{
    if (fgets(input, size, stdin) == NULL)
    {
        if (feof(stdin))
        {
            prompt();
            exit(EXIT_SUCCESS);
        }
        else
        {
            output("Check input for errors.\n");
            exit(EXIT_FAILURE);
        }
    }
    input[strcspn(input, "\n")] = '\0';
}
