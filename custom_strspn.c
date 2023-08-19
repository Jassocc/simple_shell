#include "shell.h"

/**
 * custom_strspn - custom implementation of strspn
 * @s: string to search
 * @charset: chars to search
 * Return: length
 */
size_t custom_strspn(const char *s, const char *chset)
{
	size_t len;

	len = 0;
	while (*s && custom_strchr(chset, *s))
	{
		s++;
		len++;
	}
	return (len);
}
