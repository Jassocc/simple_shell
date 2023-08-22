#include "shell.h"

/**
 * custom_strlen - gets len of string
 * @string: string
 * @position: pos
 * @delimet: delimeter
 * Return: len of string
 */

int custom_strlen(char *string, int position, char delimet)
{
	int l;

	l = 0;
	while ((string[position] != delimet) && (string[position] != '\0'))
	{
		position++;
		l++;
	}
	return (l);
}
