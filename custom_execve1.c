#include "shell.h"

/**
 * cut_exit - free typed cmd
 * @string: cmd
 * @env: list
 */
void cut_exit(char **string, list_t *env)
{
	free_dp(string);
	free_list(env);
	_exit(0);
}
/**
 * custom_execve - execute cmd
 * @cmd: cmd
 * @env: env
 * @number: num
 * Return: 0
 */
int custom_execve(char **cmd, list_t *env, int number)
{
	char *hol;
	int sta = 0, tok = 0;
	pid_t pid;

	if (access(cmd[0], F_OK) == 0)
	{
		hol = cmd[0];
		tok = 1;
	}
	else
	{
		hol = custom_wh(cmd[0], env);
	}
	if (access(hol, X_OK) != 0)
	{
		havent_found(cmd[0], number, env);
		free_dp(cmd);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hol, cmd, NULL) == -1)
			{
				havent_found(cmd[0], number, env);
				cut_exit(cmd, env);
			}
		}
		else
		{
			wait(&sta);
			free_dp(cmd);
			if (tok == 0)
				free(hol);
		}
	}
	return (0);
}
