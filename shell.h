#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

#define MAX_INPUT 1024
#define MAX_TOKENS 100


// Function prototypes
char **tokenize(char *line);
int launch(char **args);
int execute(char **args);  
void print_env(void);

#endif
