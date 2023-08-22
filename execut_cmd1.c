#include "shell.h"

/**
 * execute_cmd - executes command from user input
 * @tok: cmd to be executed
 * @env: custom getenv
 * @number: num
 * @cmd: cmd line
 * Return: a
 */
int execute_cmd(char **tok, list_t *env, int number, char **cmd)
{
	int a = 0;

	if (custom_strncmp(tok[0], "exit") == 0)
	{	a = exit_builtin(tok, env, number, cmd);
	}
	else if (custom_strncmp(tok[0], "env") == 0)
	{	custom_envbuiltin(tok, env);
		a = 1;
	}
	else if (custom_strncmp(tok[0], "cd") == 0)
	{	a = custom_cd(tok, env, number);
	}
	else if (custom_strncmp(tok[0], "setenv") == 0)
	{	custom_setenv(&env, tok);
		a = 1;
	}
	else if (custom_strncmp(tok[0], "unsetenv") == 0)
	{	custom_unsetenv(&env, tok);
		a = 1;
	}
	return (a);
}
