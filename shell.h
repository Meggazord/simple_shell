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

void prompt(void);
void get_input(char *input, size_t max_size);
void tokenize_input(const char *input, char **args);
void execute_command(char **args);
void execute(const char *input);
void execute_child(const char *input);
void exit_shell(void);
void handle_path(char **args);
char *get_program_name(char *argv[]);
void output(const char *result);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *var);

#endif
