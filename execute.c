#include "shell.h"

int execute(char **args)
{
  if (args[0] == NULL)
  {
    return (1);
  }

  if (strcmp(args[0], "exit") == 0)
  {
    exit(EXIT_SUCCESS);
  }

  if (strcmp(args[0], "env") == 0)
  {
    print_env();
    return (1);
  }

  return launch(args);  
}
