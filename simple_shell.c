#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>

/* Function prototypes */
char **tokenize(char *line);
int launch(char **args);
int execute(char **args);

int main(void)
{
  char *line;
  size_t size = MAX_INPUT_SIZE;
  tokens_t tokens;

  while (1) {
    
    printf("#cisfun$ ");
    getline(&line, &size, stdin);
    
    tokens.tokens = tokenize(line);

    execute(tokens.tokens);
    
    free(tokens.tokens);
  }

  return 0;
}

/* Tokenize the input line */
char **tokenize(char *line)
{
  char **tokens = malloc(MAX_TOKENS * sizeof(char*));
  char *token;
  int i = 0;

  if (!tokens) {
    fprintf(stderr, "Error allocating memory\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " ");
  
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " "); 
  }

  tokens[i] = NULL;
  return tokens;
}

/* Launch a program */
int launch(char **args) 
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    exit(EXIT_FAILURE);
  } else {
    waitpid(pid, &status, WUNTRACED);
  }

  return 1;
}

/* Execute commands */
int execute(char **args)
{
  if (args[0] == NULL) {
    return 1;
  }

  if (strcmp(args[0], "exit") == 0) {
    exit(EXIT_SUCCESS);
  }

  if (strcmp(args[0], "env") == 0) {
    print_env();
    return 1;
  }

  launch(args);

  return 1;
}

/* Print environment */
void print_env(void) 
{
  extern char **environ;
  int i = 0;

  while (environ[i] != NULL) {
    printf("%s\n", environ[i++]); 
  }
}

