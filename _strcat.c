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
	size_t i;

	for (i = 0; sr[i] != '\0' && d_length < d_size - 1; i++, d_length++)
	{
		d[d_length] = sr[i];
	}
	d[d_length] = '\0';
	return (d_length);
}
