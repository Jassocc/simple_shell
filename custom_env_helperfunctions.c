#include "shell.h"

/**
 * duplicate_environment - duplicates env
 * @src_env: source env
 * Return: duplicated env
 */
char **duplicate_environment(char **src_env)
{
	int num_var = 0, i, j;
	char **duplicate = NULL;

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
		if (duplicate[i] == NULL)
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
 * @n: name of env variable
 * @v: value of env variable
 * @n_le: length of name
 * @v_le: length of value
 * Return: entry
 */
char *create_env_entry(const char *n, const char *v, size_t n_le, size_t v_le)
{
	size_t entry_len = n_le + 1 + v_le + 1;
	char *entry;
	size_t pos, i;

	entry = (char *)malloc(entry_len);
	if (entry == NULL)
	{
		return (NULL);
	}
	pos = 0;
	for (i = 0; i < n_le; i++)
	{
		entry[pos++] = n[i];
	}
	entry[pos++] = '=';
	for (i = 0; i < v_le; i++)
	{
		entry[pos++] = v[i];
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
 * @n_en: entry for env variable
 * @n_len: length of name
 * @o: overwrite function
 */
void update_or_add_env(char **env, const char *n_en, size_t n_len, int o)
{
	size_t env_count = 0;

	while (env[env_count] != NULL)
	{
		if (custom_strncmp(env[env_count], n_en, n_len) == 0 &&
				env[env_count][n_len] == '=')
		{
			if (o)
			{
				free(env[env_count]);
				env[env_count] = c_strdup(n_en);
				return;
			}
			else
			{
				return;
			}
		}
		env_count++;
	}
	env[env_count] = c_strdup(n_en);
	env[env_count + 1] = NULL;
}
