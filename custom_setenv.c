#include "shell.h"

/**
 * custom_setenv - custom implementation of set env
 * @name: env variable name
 * @value: value to set
 * @overw: overwrite flag
 * Return: 0 on success
 */
int custom_setenv(const char *name, const char *value, int overw)
{
	size_t name_len = custom_strlen(name), value_len = custom_strlen(value);
	char *env_entry, **env_p = environ, **new_env;
	size_t new_entry_len = name_len + 1 + value_len + 1, i, env_count;

	if (name == NULL || name[0] == '\0' || value == NULL)
	{
		return (-1); }
	while (*env_p != NULL)
	{
		if (custom_strncmp(*env_p, name, name_len) == 0 && (*env_p)[name_len] == '=')
		{
			if (overw)
			{
				env_entry = malloc(new_entry_len);
				if (env_entry == NULL)
				{
					return (-1);
				}
				custom_memcpy(env_entry, name, name_len);
				env_entry[name_len] = '=';
				custom_memcpy(env_entry + name_len + 1, value, value_len + 1);
				free(*env_p);
				*env_p = env_entry;
				my_printf("Overwriting environment variable: %s=%s\n", name, value);
				return (0);
			}
			else
			{
				return (0);
			}
		}
		env_p++;
	}
	env_entry = malloc(new_entry_len);
	if (env_entry == NULL)
	{
		return (-1);
	}
	custom_memcpy(env_entry, name, name_len);
	env_entry[name_len] = '=';
	custom_memcpy(env_entry + name_len + 1, value, value_len + 1);
	env_count = 0;
	while (environ[env_count] != NULL)
		env_count++;
	new_env = malloc((env_count + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		free(env_entry);
		return (-1);
	}
	for (i = 0; i < env_count; i++)
		new_env[i] = environ[i];
	new_env[env_count] = env_entry;
	new_env[env_count + 1] = NULL;
	environ = new_env;
	return (0);
}
