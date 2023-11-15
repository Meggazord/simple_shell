#include "shell.h"
/**
 * _getline - reads a line
 * Return: pointer to the line
 */
char *_getline(void)
{
int buffsize = BUFF_SIZE;
int index = 0, c;
char *buff = (char *)malloc(sizeof(char) * buffsize);
if (!buffer)
{
perror("Unable to allocate buffer");
exit(EXIT_FAILURE);
}
while (1)
{
c = _getchar();
if (c == EOF || c == '\n')
{
buffer[index] = '\0';
return (buffer);
}
else
buffer[index] = c;
index++;
if (index >= buffsize)
{
int oldsize = buffsize;
buffsize += BUFF_SIZE;
buffer = _realloc(buffer, oldsize, buffsize);
if (!buffer)
{
perror("Unable to allocate buffer");
exit(EXIT_FAILURE);
}
}
}
}
/**
 * parse_line - parses line of input
 * @line: input line
 * Return: array of tokens
 */
char **parse_line(char *line)
{
char **tokens;
if (line == NULL)
return (NULL);
tokens = strtow(line);
return (tokens);
}
