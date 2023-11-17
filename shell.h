#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

/**
 * struct tokens_s - Structure to store tokenized command line
 *
 * @tokens: An array of tokens
 * @token_count: The total number of tokens
 *
 */
typedef struct tokens_s
{
        char **tokens;
        int token_count;
} tokens_t;

/* Prototypes */
int execute_command(tokens_t *tokens);
void free_tokens(tokens_t *tokens);
void print_env(void);
char **tokenize(char *line); 
int execute(char **args);

#endif

