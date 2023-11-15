#include "shell.h"
#include <unistd.h>
#include <string.h>
/**
 * TJ_print - writes a character to stdout
 * @string: characters to be inputted
 *
 * Return: 1 on success , -1 on error and errno is set appropriatly
 */
void TJ_print(const char *string)
{
write(STDOUT_FILENO, string, strlen(string));
}
