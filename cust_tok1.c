#include "shell.h"

/**
 * custom_size - returns delim
 * @string: cmd
 * @delimet: delimeter
 * Return: tokens
 */
int custom_size(char *string, char delimet)
{
	int a, number;

	a = 0;
	number = 0;
	while (string[a] != '\0')
	{
		if (string[a] == delimet)
		{
			number++;
		}
		a++;
	}
	return (number);
}
/**
 * cust_tok - tokenize a string
 * @string: cmd
 * @delimet: delimeter
 * Return: array
 */
char **cust_tok(char *string, char *delimet)
{
	int buffers = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
	char **tokenizer = NULL, ch;

	ch = delimet[0];
	buffers = custom_size(string, ch);
	tokenizer = malloc(sizeof(char *) * (buffers + 2));
	if (tokenizer == NULL)
	{
		return (NULL);
	}
	while (string[e] != '\0')
		e++;
	while (b < e)
	{
		d = custom_strlen(string, b, ch);
		tokenizer[a] = malloc(sizeof(char) * (d + 1));
		if (tokenizer[a] == NULL)
			return (NULL);
		c = 0;
		while ((string[b] != ch) && (string[b] != '\0'))
		{
			tokenizer[a][c] = string[b];
			c++;
			b++;
		}
		tokenizer[a][c] = '\0';
		a++;
		b++;
	}
	tokenizer[a] = NULL;
	return (tokenizer);
}
