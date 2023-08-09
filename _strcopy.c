#include "shell.h"

/**
 * strcopy - copies a string
 * @d: string to be copied to
 * @s: string to copy to
 * Return: original string
 */
char *strcopy(char *d, const char *s)
{
	char *origin = d;

	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (origin);
}
