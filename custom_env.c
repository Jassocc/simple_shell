#include "shell.h"

/**
 * custom_envbuiltin - custom implementation of env
 * @command: cmd var
 * @env: custom env
 * Return: 0
 */
char custom_envbuiltin(char *command[], char **env)
{
	char **curr_env = env;

	(void)command;

	while (*curr_env != NULL)
	{
		my_printf("%s\n", *curr_env);
		curr_env++;
	}
	return (0);
}
