#include "shell.h"

int launch(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS); // Added exit after execvp
    }
    else if (pid < 0)
    {
        perror("Error forking");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
