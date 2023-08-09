#include "shell.h"

/**
 * _stringcat - concactenates two string
 * @d: string 1
 * @d_size: size of string 1
 * @sr: string 2
 * Return: two string concactenated
 */

size_t _stringcat(char *d, size_t d_size, const char *sr)
{
	size_t d_length = custom_strlen(d);
	size_t sr_length = custom_strlen(sr);
	size_t i, j;

	for (i = 0, j = 0; j < sr_length && i < d_size - 1; i++, j++)
	{
		d[i] = sr[j];
	}
	d[i] = '\0';
	return (d_length + sr_length);
}
