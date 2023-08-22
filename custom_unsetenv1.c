#include "shell.h"

/**
 * get_envir - find env
 * @env: var
 * @name: var name
 * Return: idx
 */
int get_envir(list_t *env, char *name)
{
	int k, idx;

	k = 0;
	idx = 0;
	while (env != NULL)
	{
		k = 0;
		while ((env->var)[k] == name[k])
		{
			k++;
		}
		if (name[k] == '\0')
		{
			break;
		}
		env = env->next;
		idx++;
	}
	if (env == NULL)
	{
		return (-1);
	}
	return (idx);
}
/**
 * custom_unsetenv - remove node
 * @env: linked list
 * @string: cmd
 * Return: 0
 */
int custom_unsetenv(list_t **env, char **string)
{
	int idx, k;

	idx = 0;
	k = 0;
	if (string[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_dp(string);
		return (-1);
	}
	idx = get_envir(*env, string[1]);
	free_dp(string);
	if (idx == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	k = idx_node(env, idx);
	if (k == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}
/**
 * custom_setenv - remove node
 * @env: list
 * @string: cmd
 * Return: 0
 */
int custom_setenv(list_t **env, char **string)
{
	int idx = 0, k = 0;
	char *c;
	list_t *hol;

	if (string[1] == NULL || string[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_dp(string);
		return (-1);
	}
	c = custom_strdup(string[1]);
	c = custom_stringcat(c, "=");
	c = custom_stringcat(c, string[2]);
	idx = get_envir(*env, string[1]);
	if (idx == -1)
	{
		node_ended(env, c);
	}
	else
	{
		hol = *env;
		while (k < idx)
		{
			hol = hol->next;
			k++;
		}
		free(hol->var);
		hol->var = custom_strdup(c);
	}
	free(c);
	free_dp(string);
	return (0);
}
