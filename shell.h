#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/* Operators */
#define BUFF_SIZE 1024
#define TOKEN_SIZE 64
#define BUF_FLUSH -1
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}
#define SEPARATORS \
{\
"&&", "||", "#", ";" \
}
/*Functions samples */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int buffsize = BUFF_SIZE;
int index = 0, c;
char *buff = (char *)malloc(sizeof(char) * buffsize);
void shell(void);
char *_getline(void);
char **parse_line(char *);
int _getchar(void);
char *_memcpy(char *, char *, unsigned int);
char **strtow(char *);
char **strtow2(char *, char);
int _strlen(char *);
void TJ_print(const char *string);
#endif
