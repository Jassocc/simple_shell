#include "shell.h"

/**
 * custom_realloc - custom implementation of realloc
 * @p: pointer
 * @size: size of p
 * Return: NULL
 */
void *custom_realloc(void *p, size_t size)
{
	void *np;

	if (size == 0)
	{
		free(p);
		return (NULL);
	}
	np = malloc(size);
	if (np)
	{
		if (p)
		{
			custom_memcpy(np, p, size);
			free(p);
		}
		return (np);
	}
	return (NULL);
}
