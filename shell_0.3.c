#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

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

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {

            char *args[100]; 
            int i = 0;

            char *token = strtok(buffer, " ");
            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL;

            if (access(args[0], X_OK) == 0) {
                if (execve(args[0], args, NULL) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            } else {
                char *path = getenv("PATH");
                char *token, *full_path;

                token = strtok(path, ":");

                while (token != NULL) {
                    full_path = malloc(strlen(token) + strlen(args[0]) + 2);
                    if (full_path == NULL) {
                        perror("malloc");
                        exit(EXIT_FAILURE);
                    }

                    sprintf(full_path, "%s/%s", token, args[0]);

                    if (access(full_path, X_OK) == 0) {
                        if (execve(full_path, args, NULL) == -1) {
                            perror("execve");
                            exit(EXIT_FAILURE);
                        }
                    }

                    free(full_path);
                    token = strtok(NULL, ":");
                }

                printf("%s: command not found\n", args[0]);
                exit(EXIT_FAILURE);
            }
        } else {

            wait(NULL);
        }
    }


    free(buffer);

    return 0;
}