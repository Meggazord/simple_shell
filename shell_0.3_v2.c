#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 100

void execute_command(char *command, char *args[]);
char *search_path(char *command);
char **tokenize_input(char *input);

int main(void) {
    char *buffer = NULL;
    size_t bufsize = 0;

    while (1) {
        printf(":) ");

        ssize_t characters_read = getline(&buffer, &bufsize, stdin);

        if (characters_read == -1) {
            printf("\n");
            break;
        }

        buffer[characters_read - 1] = '\0';

        char **args = tokenize_input(buffer);

        if (args == NULL) {
            perror("tokenize_input");
            exit(EXIT_FAILURE);
        }

        execute_command(args[0], args);

        // Free memory allocated by tokenize_input
        free(args);
    }

    free(buffer);

    return 0;
}

void execute_command(char *command, char *args[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        if (access(command, X_OK) == 0) {
            if (execve(command, args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            char *full_path = search_path(command);

            if (full_path != NULL) {
                if (execve(full_path, args, NULL) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("%s: command not found\n", command);
                exit(EXIT_FAILURE);
            }
        }
    } else {
        wait(NULL);
    }
}

char *search_path(char *command) {
    char *path = getenv("PATH");
    char *token, *full_path;

    token = strtok(path, ":");

    while (token != NULL) {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}

char **tokenize_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    if (args == NULL) {
        return NULL;
    }

    int i = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;

    return args;
}
