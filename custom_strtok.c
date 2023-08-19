#include "shell.h"

/**
 * custom_strtok - custom implementation of strtok
 * @s: string to tokenize
 * @del: delimeter sstring
 * Return: pointer to next token;
 */
char *custom_strtok(char *s, const char *del)
{
	static char *savep = NULL;
	char *tok, *next;

	if (s == NULL)
	{
		s = savep;
	}
	s = s + custom_strspn(s, del);
	if (*s == '\0')
	{
		savep = s;
		return (NULL);
	}
	next = custom_strpbrk(s, del);
	if (next != NULL)
	{
		*next = '\0';
		savep = next + 1;
	}
	else
	{
		savep = s + custom_strlen(s);
	}
	tok = s;
	return (tok);
}
