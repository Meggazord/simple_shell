#include "shell.h"
/**
 * _strcmp - Compare 2 strings
 * @s1: first string ointer
 * @s2: second string pointer
 * Return: negative if s1 < s2, 0 if s1 == s2, positive if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
    int x;

    x = 0;

    while (s1[x] && s2[x] && s1[x] ==  s2[x])
        x++;
    return (s1[x] - s2[x]);
}
