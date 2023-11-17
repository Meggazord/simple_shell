#include "shell.h"

int main(void)
{
  char *line;
  size_t size = MAX_INPUT;
  char **args;

  while (1)
  {
    printf(":) ");
    getline(&line, &size, stdin);

    args = tokenize(line);
    
    execute(args);

    free(args);
  }

  return (0);
}
