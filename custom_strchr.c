#include "shell.h"

/**
 * custom_strchr - custom implementation of strchr
 * @s: sring to search
 * @ch: chars to search
 * Return: pointer
 */
char *custom_strchr(const char *s, int ch)
{
	while (*s)
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
