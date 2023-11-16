#include "shell.h"
/**
 * print_environment - Execute a command received as input
 */

void print_environment(void)
{
    char **env = environ;
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
