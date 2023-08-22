#include "shell.h"

/**
 * strcopy - copies a string
 * @d: string to be copied to
 * @s: string to copy to
 * Return: original string
 */
char *custom_strcopy(char *d, char *s)
{
	int a, l;

	for (l = 0; s[l] != '\0'; l++)
	{
		;
	}
	for (a = 0; a <= l; a++)
	{
		d[a] = s[a];
	}
	return (d);
}
