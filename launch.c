#include "shell.h"

int launch(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Check if the command includes a path
        if (args[0][0] == '/') {
            if (execve(args[0], args, environ) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        } else {
            // If no path is provided, search in directories listed in PATH
            char *path = getenv("PATH");
            if (path != NULL) {
                char *token = strtok(path, ":");
                while (token != NULL) {
                    char command[MAX_INPUT];
                    snprintf(command, sizeof(command), "%s/%s", token, args[0]);
                    if (execve(command, args, environ) == -1) {
                        token = strtok(NULL, ":");
                    } else {
                        exit(EXIT_SUCCESS);
                    }
                }
            }
            // If the command is not found
            fprintf(stderr, "Error: Command not found\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS); // Added exit after execve
    } else if (pid < 0) {
        perror("Error forking");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
