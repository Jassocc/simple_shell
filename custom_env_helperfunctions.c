#include "shell.h"

/**
 * cuplicate_environment - duplicates env
 * @src_env: source env
 * Return: duplicated env
 */
char **duplicate_environment(char **src_env)
{
	int num_var = 0, i, j;
	char ** duplicate = NULL;

	while (src_env[num_var] != NULL)
	{
		num_var++;
	}
	duplicate = (char **)malloc((num_var + 1) * sizeof(char *));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < num_var; i++)
	{
		duplicate[i] = c_strdup(src_env[i]);
		if (duplicate [i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(duplicate[j]);
			}
			free(duplicate);
			return (NULL);
		}
	}
	duplicate[num_var] = NULL;
	return (duplicate);
}
/**
 * create_env_entry - creation of env variable
 * @name: name of env variable
 * @value: value of env variable
 * @name_len: length of name
 * @value_len: length of value
 * Return: entry
 */
char *create_env_entry(const char *name, const char *value, size_t name_len, size_t value_len)
{
	size_t entry_len = name_len + 1 + value_len + 1;
	char *entry;
	size_t pos, i;

	entry = (char *)malloc(entry_len);
	if (entry == NULL)
	{
		return (NULL);
	}
	pos = 0;
	for (i = 0; i < name_len; i++)
	{
		entry[pos++] = name[i];
	}
	entry[pos++] = '=';
	for (i = 0; i < value_len; i++)
	{
		entry[pos++] = value[i];
	}
	entry[pos] = '\0';
	return (entry);
}
/**
 * free_environment - free function
 * @env: env to free
 */
void free_environment(char **env)
{
	size_t i;

	if (env == NULL)
	{
		return;
	}
	for (i = 0; env[i] != NULL; i++)
	{
		free(env[i]);
	}
	free(env);
}
/**
 * update_or_add_env - modifies or adds to a env
 * @env: environment variable
 * @new_entry: entry for env variable
 * @name_len: length of name
 * @overw: overwrite function
 */
void update_or_add_env(char **env, const char *new_entry, size_t name_len, int overw)
{
	size_t env_count = 0;
	
	while (env[env_count] != NULL)
	{
		if (custom_strncmp(env[env_count], new_entry, name_len) == 0 &&
				env[env_count][name_len] == '=')
		{
			if (overw)
			{
				free(env[env_count]);
				env[env_count] = c_strdup(new_entry);
				return;
			}
			else
			{
				return;
			}
		}
		env_count++;
	}
	env[env_count] = c_strdup(new_entry);
	env[env_count + 1] = NULL;
}
