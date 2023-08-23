#include "shell.h"

/**
 * exit_builtin - custom exit function
 * @cmd: cmd argument
 * @env: environment
 * @number: num
 * @string: string
 * Return: 0
 */
int exit_builtin(char **string, list_t *env, int number, char **cmd)
{
	int status = 0;

	if (string[1] != NULL)
	{
		status = custom_atoi(string[1]);
	}
	if (status == -1)
	{
		invalid_num(string[1], number, env);
		free_dp(string);
		return (2);
	}
	free_dp(string);
	free_list(env);
	if (cmd != NULL)
	{
		free_dp(cmd);
	}
	exit(status);
}
