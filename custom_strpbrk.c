#include "shell.h"

/**
 * custom_strpbrk - custom implementation of strpbrk
 * @s: string to search
 * @chset: chars to search
 * Return: popinter to first occurence
 */
char *custom_strpbrk(const char *s, const char *chset)
{
	while (*s)
	{
		if (custom_strchr(chset, *s))
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
