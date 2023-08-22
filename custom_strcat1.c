#include "shell.h"

/**
 * custom_stringcat - concactenates two string
 * @d: string 1
 * @sr: string 2
 * Return: two string concactenated
 */

char *custom_stringcat(char *d, char *sr)
{
	int length1 = 0, length2 = 0, tot = 0, h = 0;

	while (d[length1] != '\0')
	{
		length1++;
		tot++;
	}
	while (sr[length2] != '\0')
	{
		length2++;
		tot++;
	}
	d = custom_realloc(d, length1, sizeof(char) * tot + 1);
	h = 1;
	while (sr[h] != '\0')
	{
		d[length1] = sr[h];
		length1++;
		h++;
	}
	d[length1] = '\0';
	return (d);
}
