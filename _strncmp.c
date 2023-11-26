#include "shell.h"
/**
 * _strncmp - Compare 2 strings
 * @s1: first string ointer
 * @s2: second string pointer
 * @n: number to be compared
 * Return: Negative if s1 < s2, 0 if s1 == s2, positive if s1 > s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}
