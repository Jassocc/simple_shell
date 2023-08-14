#include "shell.h"

/**
 * c_strdup - duplicate string
 * @str: string
 * Return: pointer
 */
char *c_strdup(const char *str)
{
	size_t length = custom_strlen(str) + 1;
	char *duplicate = (char *)malloc(length);

	if (duplicate)
	{
		strcopy(duplicate, str);
	}
	return (duplicate);
}
