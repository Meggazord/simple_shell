#include "shell.h"

char **tokenize(char *line)
{
    char *token;
    int i = 0;
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    
    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \n"); // Tokenize by space and newline

    while (token != NULL && i < MAX_TOKENS - 1) // Ensure the limit of tokens
    {
        tokens[i] = strdup(token); // Using strdup to duplicate the string
        token = strtok(NULL, " \n");
        i++;
    }

    tokens[i] = NULL;
    return (tokens);
}
