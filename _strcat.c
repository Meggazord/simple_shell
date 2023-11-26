#include "shell.h"

/**
 * _strcat - a function to concatenate 2 strings
 * @dest: Pointer of string 1
 * @src: Pointer of string 2
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int d, s;

	d = 0;
	s = 0;

	while (dest[d])
	{
		d++;
	}

	while (src[s])
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';

	return (dest);
}
