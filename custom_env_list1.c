#include "shell.h"

/**
 * envir_list - create link list
 * @env: enviropnment
 * Return: list
 */
list_t *envir_list(char **env)
{
	list_t *top;
	int a = 0;

	top = NULL;
	while (env[a] != NULL)
	{
		node_ended(&top, env[a]);
		a++;
	}
	return (top);
}
/**
 * custom_envbuiltin - prints env
 * @string: cmd
 * @env: environment
 * Return: 0
 */
int custom_envbuiltin( char **string, list_t *env)
{
	free_dp(string);
	my_printf(env);

	return (0);
}
