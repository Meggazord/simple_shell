#include "shell.h"

/**
 *_erputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _erputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _erputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _erputchar(char c)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(2, buf, s);
		s = 0;
	}
	if (c != BUF_FLUSH)
		buf[s++] = c;
	return (1);
}

/**
 * _eputfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputfd(char c, int fd)
{
	static int g;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || g >= WRITE_BUF_SIZE)
	{
		write(fd, buf, g);
		g = 0;
	}
	if (c != BUF_FLUSH)
		buf[g++] = c;
	return (1);
}

/**
 *_eputsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _eputsfd(char *str, int fd)
{
	int f = 0;

	if (!str)
		return (0);
	while (*str)
	{
		f += _putfd(*str++, fd);
	}
	return (f);
}
