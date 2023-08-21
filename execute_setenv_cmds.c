#include "shell.h"

/**
 * execute_setenv - execution of the setenv cmd
 * @args: argument to take
 * Return: 0 if succesfull
 */
int execute_setenv(char *args[])
{
	int result;

	if (args[1] != NULL && args[2] != NULL && args[3] == NULL)
	{
		result = custom_setenv(args[1], args[2], 1);
		if (result == -1)
		{
			perror("setenv failed");
			return (-1);
		}
	}
	else
	{
		my_printf("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	return (0);
}
/**
 * execute_unsetenv - execution of unset function
 * @args: argument to remeove
 * Return: 0 if success, -1 if  fail
 */
int execute_unsetenv(char *args[])
{
	int result;
	if (args[1] != NULL && args[2] == NULL)
	{
		result = custom_unsetenv(args[1]);
		if (result == -1)
		{
			perror("unsetenv failed");
			return (-1);
		}
		return (0);
	}
	else
	{
		my_printf("Usage: unsetenv VARIABLE\n");
		return (-1);
	}
	return (-1);
}
