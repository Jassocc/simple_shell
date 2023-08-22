#include "shell.h"

/**
 * length_number - count number of 0
 * @numbo: number
 * Return: count
 */
int length_number(int numbo)
{
	int appen, number;

	appen = 0;
	number = numbo;
	while (number > 9 || number < -9)
	{
		number /= 10;
		appen++;
	}
	return (appen);
}
/**
 * int_transfer - turns int to str
 * @lumbo: int
 * Return: return int
 */
char *int_transfer(int lumbo)
{
	int dig, ts, a = 0, l = 0, z;
	char *results;

	dig = lumbo;
	ts = 1;
	if (lumbo < 0)
	{
		l = 1;
	}
	results = malloc(sizeof(char) * (length_number(dig) + 2 + l));
	if (results == NULL)
	{
		return (NULL);
	}
	if (lumbo < 0)
	{
		results[a] = '-';
		a++;
	}
	for (z = 0; dig > 9 || dig < -9; z++)
	{
		dig /= 10;
		ts *= 10;
	}
	for (dig = lumbo; z >= 0; z--)
	{
		if (dig < 0)
		{
			results[a] = (dig / ts) * -1 + '0';
			a++;
		}
		else
		{
			results[a] = (dig / ts) + '0';
			a++;
		}
		dig %= ts;
		ts /= 10;
	}
	results[a] = '\0';
	return (results);
}
