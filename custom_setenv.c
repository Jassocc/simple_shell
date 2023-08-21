#include "shell.h"
#define MEMORY_TRACKING_ENABLED 1
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
	char *env_entry = NULL, **env_p = environ, **new_env = NULL;
	size_t i, env_count;

	if (name == NULL || name[0] == '\0' || value == NULL)
	{
		return (-1); }
	while (*env_p != NULL)
	{
		if (custom_strncmp(*env_p, name, name_len) == 0 && (*env_p)[name_len] == '=')
		{
			if (overw)
			{
				free(*env_p);
				env_entry = create_env_entry(name, value, name_len, value_len);
				if (env_entry == NULL)
				{
					printf("Failed to Allocate MEmory for env_entry: 1\n");
					return (-1);
				}
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
	env_entry = create_env_entry(name, value, name_len, value_len);
	if (env_entry == NULL)
	{
		printf("Failed to Allocate MEmory for env_entry: 2\n");
		return (-1);
	}
	if (*env_p != NULL) 
	{
		free(*env_p);
		*env_p = env_entry; }
	else
	{
	env_count = 0;
	while (environ[env_count] != NULL)
		env_count++;
	new_env = (char **)malloc((env_count + 2) * sizeof(char *));
	if (new_env == NULL)
	{	
		printf("Failed to Allocate MEmory for new_env\n");
		free(env_entry);
		return (-1);
	}
	for (i = 0; i < env_count; i++)
		new_env[i] = environ[i];
	new_env[env_count] = env_entry;
	new_env[env_count + 1] = NULL;
	environ = new_env;
	}
	return (0);
}
/**
 * set_custon_env - create a custom env
 * @name: name of var
 * @value: value of env
 * @overw: overwrite function
 * Return: env
 */
int set_custom_env(const char *name, const char *value, int overw)
{
	size_t name_len = custom_strlen(name), value_len = custom_strlen(value);
	char *env_entry = NULL;
	char **new_environ = NULL;

	new_environ = duplicate_environment(environ);
	if (new_environ == NULL)
	{
		return (-1);
	}
	env_entry = create_env_entry(name, value, name_len, value_len);
	if (env_entry == NULL)
	{
		free_environment(new_environ);
		return (-1);
	}
	update_or_add_env(new_environ, env_entry, name_len, overw);
	free_environment(environ);
	environ = new_environ;
	return (0);
}
