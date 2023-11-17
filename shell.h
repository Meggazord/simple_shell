#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void execute_command(char *buffer);
void print_environment(void);
void execute_command_child(char *buffer);
void execute_command_in_path(char *args[]);

#endif
