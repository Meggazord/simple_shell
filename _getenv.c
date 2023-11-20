#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @var: Name of the environment variable to retrieve
 *
 * Return: Value of the environment variable if found, NULL otherwise
 */

char *_getenv(const char *var)
{
    extern char **environ;
    size_t len;
    char **env;

    if (var == NULL || environ == NULL)
        return (NULL);

    len = _strlen(var);

    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, var, len) == 0 && (*env)[len] == '=')
        {
            return (*env + len + 1);
        }
    }

    return (NULL);
}
