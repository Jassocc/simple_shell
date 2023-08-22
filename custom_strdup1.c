#include "shell.h"

/**
 * c_strdup - duplicate string
 * @str: string
 * Return: pointer
 */
char *custom_strdup(char *string)
{
	char *dupli;
	int a, l = 0;

	if (string == NULL)
	{
		return (NULL);
	}
	while (*(string + l))
	{
		l++;
	}
	l++;
	dupli = malloc(sizeof(char) * l);
	if (dupli == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (a < l)
	{
		*(dupli + a) = *(string + a);
		a++;
	}
	return (dupli);
}
