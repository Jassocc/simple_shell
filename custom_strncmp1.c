#include "shell.h"

/**
 * custom_strncmp - compare two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if success
 */
int custom_strncmp(char *str1, char *str2)
{
	int a;

	a = 0;
	while (*(str1 + a) == *(str2 + a) && *(str1 + a))
	{
		a++;
	}
	if (*(str2 + a))
	{
		return (*(str1 + a) - *(str2 + a));
	}
	else
	{
		return (0);
	}
}
