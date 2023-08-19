#include "shell.h"

/**
 * custom_atoi - custom implementation of atoi
 * @s: string to convert to int
 * Return: int
 */
int custom_atoi(const char *s)
{
	int res, sign, i;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
	{
		return (-1);
	}
	return (res * sign);
}
