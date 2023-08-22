#include "shell.h"
/**
 * main - main function for the shell
 * @ac: void
 * @argv: vector for arguments
 * @env: environment var
 * Return: 0 if succes, -1 if fail
 */
int main(int ac, char **argv, char **env)
{
	(void)ac, (void)argv;

	print_prompt(env);
	return (0);
}
/**
 * print_prompt - prints promps
 * @envir: env variables
 * Return: 0
 */
int print_prompt(char **envir)
{
	list_t *env;
	size_t a = 0, b = 0;
	int cl_n = 0, ext_status = 0;
	char *cmd, *cmd_n;
	char **tok;

	env = envir_list(envir);
	do {
		cl_n++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_inter(env);
		signal(SIGINT, contc);
		cmd = NULL, a = 0;
		a = custom_getline(&cmd);
		contd(a, cmd, env);
		cmd_n = cmd;
		cmd = no_space(cmd);
		b = 0;
		while (cmd[b] != '\n')
			b++;
		cmd[b] = '\0';
		if (cmd[0] == '\0')
		{	free(cmd_n);
			continue;
		}
		tok = NULL;
		tok = custom_strtok(cmd, " ");
		if (cmd_n != NULL)
			free(cmd_n);
		ext_status = execute_cmd(tok, env, cl_n, NULL);
		if (ext_status)
			continue;
		ext_status = custom_execve(tok, env, cl_n);
	} while (1);
	return (ext_status);
}
