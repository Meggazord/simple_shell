#include "shell.h"

int launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    execvp(args[0], args);
    exit(EXIT_FAILURE);
  }

  else
  {
    waitpid(pid, &status, WUNTRACED);
  }

  return (1);
}
