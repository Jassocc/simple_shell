#include "shell.h"

/**
 * custom_getenv - implementation of getenv
 * @name: eviron var name
 * Return: value
 */
char *custom_getenv(const char *name)
{
	size_t name_len = custom_strlen(name);
	int i;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (custom_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}
