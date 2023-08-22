#include "shell.h"

/**
 * ignorance - ignores spaces and newlines
 * @evars: environmental variables
 * Return: string
 */
char *ignorance(char *evars)
{
	while (*evars == ' ' || *evars == '\n')
	{
		evars++;
	}
	return (evars);
}
/**
 * non_inter - handles pipes
 * @env: env var
 */
void non_inter(list_t *env)
{
	size_t a = 0, num = 0;
	int cli_n = 0, ext_status = 0;
	char *cmd = NULL, *cmd_n = NULL, **line_p, **tok;

	a = custom_getline(&cmd);
	if (a == 0)
	{
		free(cmd);
		exit(0);
	}
	cmd_n = cmd;
	cmd = ignorance(cmd);
	line_p = custom_strtok(cmd, "\n");
	if (cmd_n != NULL)
	{
		free(cmd_n);
	}
	num = 0;
	while (line_p[num] != NULL)
	{
		cli_n++;
		tok = NULL;
		tok = custom_strtok(line_p[num], " ");
		ext_status = execute_cmd(tok, env, cli_n, line_p);
		if (ext_status)
		{
			num++;
			continue;
		}
		ext_status = custom_execve(tok, env, cli_n);
		num++;
	}
	free_dp(line_p);
	free_list(env);
	exit(ext_status);
}
