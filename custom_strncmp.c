#include "shell.h"

/**
 * custom_strncmp - compare two strings
 * @str1: string 1
 * @str2: string 2
 * @n: number of chars
 * Return: 0 if success
 */
int custom_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return ((int)(unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		if (str1[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
