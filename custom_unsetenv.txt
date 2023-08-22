#include "shell.h"

/**
 * custom_unsetenv - custom implementation of unsetenv
 * @name: env variable name to unset
 * Return: 0 on success, -1 if fail
 */
int custom_unsetenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (custom_strncmp(environ[i], name, custom_strlen(name)) == 0)
		{
			free(environ[i]);
			while (environ[i + 1] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			return (0);
		}
	}
	return (-1);
}
