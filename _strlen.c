#include "shell.h"

/**
 * _strlen - gives length of a string
 * @s: string
 * Return: length of string s
 */

int _strlen(const char *s)
{
	int length;

	length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
