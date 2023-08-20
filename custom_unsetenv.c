#include "shell.h"

/**
 * custom_unsetenv - custom implementation of unsetenv
 * @name: env variable name to unset
 * Return: 0 on success, -1 if fail
 */
int custom_unsetenv(const char *name)
{
	size_t name_len = custom_strlen(name);
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (custom_strncmp(environ[i], name, name_len) == 0 &&
				environ[i][name_len] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}
	}
	return (-1);
}
