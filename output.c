#include "shell.h"

void output(const char *result)
{
    write(STDOUT_FILENO, result, strlen(result));
}
