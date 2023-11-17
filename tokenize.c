#include "shell.h"

char **tokenize(char *line)
{
  char **tokens = malloc(MAX_TOKENS * sizeof(char*));
  char *token;
  int i = 0;

  if (!tokens) {
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " ");
  
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " ");
  }

  tokens[i] = NULL;
  return (tokens);
}
