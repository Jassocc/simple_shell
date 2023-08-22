#include "shell.h"

/**
 * custom_atoi - custom implementation of atoi
 * @sum: string to convert to int
 * Return: int
 */
int custom_atoi(char *sum)
{
	int a;
	unsigned int results;

	results = 0;
	a = 0;
	while (sum[a] != '\0')
	{
		if (sum[a] >= '0' && sum[a] <= '9')
		{
			results = results * 10 + (sum[a] - '0');
		}
		if (sum[a] > '9' || sum[a] < '0')
		{
			return (-1);
		}
		a++;
	}
	return (results);
}
