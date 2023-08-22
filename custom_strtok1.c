#include "shell.h"

/**
 * tok_s - return num of delim
 * @string: cmd
 * @delimet: delimeter
 * Return: num of delim
 */
int tok_s(char *string, char delimet)
{
	int a, num;

	a = 0;
	num = 0;
	while (string[a] != '\0')
	{
		if ((string[a] == delimet) && (string[a + 1] != delimet))
		{
			num++;
		}
		if ((string[a] == delimet) && (string[a + 1] == '\0'))
		{
			num--;
		}
		a++;
	}
	return (num);
}
/**
 * ign_d - returns a string without delm's
 * @string: string
 * @delimet: delimitwer
 * Return: new str
 */
char *ign_d(char *string, char delimet)
{
	while (*string == delimet)
	{
		string++;
	}
	return (string);
}
/**
 * custom_strtok - custom implementation of strtok
 * @s: string to tokenize
 * @del: delimeter sstring
 * Return: pointer to next token;
 */
char **custom_strtok(char *string, char *del)
{
	int buffers = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	char **to = NULL, ch;

	ch = del[0];
	string = ign_d(string, ch);
	buffers = tok_s(string, ch);
	to = malloc(sizeof(char *) * (buffers + 2));
	if (to == NULL)
	{
		return (NULL);
	}
	while (string[e] != '\0')
		e++;
	while (b < e)
	{
		if (string[b] != ch)
		{
			d = custom_strlen(string, b, ch);
			to[a] = malloc(sizeof(char) * (d + 1));
			if (to[a] == NULL)
				return (NULL);
			c = 0;
			while ((string[b] != ch) && (string[b] != '\0'))
			{
				to[a][c] = string[b];
				c++;
				b++;
			}
			to[a][c] = '\0';
			f++;
		}
		if (b < e && (string[b + 1] != ch && string[b + 1] != '\0'))
			a++;
		b++;
	}
	a++;
	to[a] = NULL;
	return (to);
}
