#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT 1024
#define MAX_TOKENS 100

void execute_command(char **args);
void output(const char *result);
void execute(const char *input);
void prompt(void);
void get_input(char *input, size_t size);
void handle_path(char **args);
void execute_child(const char *input);
void exit_shell(void);

#endif
