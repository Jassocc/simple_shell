#include "shell.h"

/**
 * custom_realloc - custom implementation of realloc
 * @p: pointer
 * @size: size of p
 * Return: NULL
 */
void *custom_realloc(void *p, unsigned int old_s, unsigned int n_s)
{
	void *np;
	unsigned int a;

	if (n_s == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	if (n_s == old_s)
	{
		return (p);
	}
	if (p == NULL)
	{
		np = malloc(n_s);
		if (np == NULL)
		{
			return (NULL);
		}
		else
		{
			return (np);
		}
	}
	np = malloc(n_s);
	if (np == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < old_s && a < n_s; a++)
	{
		*((char *)np + a) = *((char *)p + a);
	}
	free(p);
	return (np);
}
