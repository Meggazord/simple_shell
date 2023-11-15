#include "shell.h"
/**
 * shell - ignites the shell
 * Return: void
 */
void shell(void)
{
char *line;
char **args;
int i = 0;
write(STDOUT_FILENO, "$ ", 3);
line = _getline();
args = parse_line(line);
free(line);
if (!args)
return;
for (; args[i]; i++)
{
printf("%s\n", args[i]);
free(args[i]);
}
free(args);
}
