#include "shell.h"
/**
 * _getchar - reads a character from stdin
 * Return: character
 */
int _getchar(void)
{
char c;
if (read(STDIN_FILENO, &c, 1) == 1)
return (c);
else
return (EOF);
}
/**
 * _realloc - reallocates memory block
 * @old_size: old size memory block
 * @new_size: new size memory block
 * @ptr: pointer to memory block
 * Return: void pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_block;
if (new_size == old_size)
return (ptr);
if (ptr != NULL && new_size == 0)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
return (malloc(new_size));
new_block = malloc(new_size);
if (new_block == NULL)
return (NULL);
_memcpy(new_block, ptr, old_size);
free(ptr);
return (new_block);
}
/**
 * _memcpy -  function that copies memory area.
 * @dest: destination
 * @src: source
 * @n: buffer size
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i = 0;
for (; i < n; i++)
dest[i] = src[i];
return (dest);
}
/**
 * _strlen - length of a string
 * @s: string
 * Return: int
 */
int _strlen(char *s)
{
int l = 0;
while (s[l] != '\0' && s[l] != ' ')
l++;
return (l);
}
/**
 * strtow - splits a string
 * @str: string to split
 * Return: pointer to char pointer
 */
char **strtow(char *str)
{
char **t;
int i = 0, l = 0, strle, j;
if (str == NULL || *str == '\0')
return (NULL);
for (; str[i] != '\0'; i++)
if (str[i] != ' ')
if (i - 1 < 0 || str[i - 1] == ' ')
l++;
if (l == 0)
return (NULL);
t = (char **)malloc(sizeof(char *) * (l + 1));
if (t == NULL)
return (NULL);
for (i = 0; i < l; i++)
{
strle = 0;
while (*str != '\0')
{
if (*str != ' ')
{
strle = _strlen(str);
break;
}
str++;
}
t[i] = (char *)malloc(sizeof(char) * strle + 1);
if (t[i] == NULL)
{
for (j = 0; j < i; j++)
free(t[j]);
free(t);
return (NULL);
}
for (j = 0; j < strle; j++, str++)
t[i][j] = *str;
t[i][j] = '\0';
}
t[l] = NULL;
return (t);
}
