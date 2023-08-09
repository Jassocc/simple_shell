#include "shell.h"

/**
 * custom_strlen - gets len of string
 * @str: string
 * Return: len of string
 */

size_t custom_strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}
