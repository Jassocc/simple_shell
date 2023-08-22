#include "shell.h"

/**
 * cd_setenv - custom implementation of setenv
 * @env: env list
 * @n: variable name
 * @d: directory
 * Return: 0
 */
int cd_setenv(list_t **env, char *n, char *d)
{
	int idx = 0, b = 0;
	char *c;
	list_t *hol;

	c = custom_strdup(n);
	c = custom_stringcat(c, "=");
	c = custom_stringcat(c, d);
	idx = get_envir(*env, n);
	hol = *env;
	while (b < idx)
	{
		hol = hol->next;
		b++;
	}
	free(hol->var);
	hol->var = custom_strdup(c);
	free(c);
	return (0);
}
/**
 * cd_home - changes to home
 * @env: update to PATH
 * @cur: current path
 */
void cd_home(list_t *env, char *cur)
{
	char *root = NULL;

	root = custom_look_env("HOME", env);
	cd_setenv(&env, "OLDPWD", cur);
	free(cur);
	if (access(root, F_OK) == 0)
		chdir(root);
	cur = NULL;
	cur = getcwd(cur, 0);
	cd_setenv(&env, "PWD", cur);
	free(cur);
	free(root);
}
/**
 * execute_cmd_cd - executes cd
 * @env: var
 * @cur: current
 * @d: directory
 * @string: string arg
 * @number: number of args
 * Return: 0
 */
int execute_cmd_cd(list_t *env, char *cur, char *d, char *string, int number)
{
	int a;

	if (access(d, F_OK) == 0)
	{
		cd_setenv(&env, "OLDPWD", cur);
		free(cur);
		chdir(d);
		cur = NULL;
		cur = getcwd(cur, 0);
		cd_setenv(&env, "PWD", cur);
		free(cur);
	}
	else
	{
		cannot_change(string, number, env);
		free(cur);
		a = 2;
	}
	return (a);
}
/**
 * custom_cd - change dir
 * @string: cmd
 * @env: environment
 * @number: n command
 * Return: 0
 */
int custom_cd (char **string, list_t *env, int number)
{
	char *cur = NULL, *d = NULL;
	int ext_status = 0;

	cur = getcwd(cur, 0);
	if (string[1] != NULL)
	{
		if (string[1][0] == '~')
		{
			d = custom_look_env("HOME", env);
			d = custom_stringcat(d, string[1]);
		}
		else if (string[1][0] == '-')
		{
			if (string[1][1] == '\0')
			{
				d = custom_look_env("OLDPWD", env);
			}
		}
		else
		{
			if (string[1][0] != '/')
			{
				d = getcwd(d, 0);
				d = custom_stringcat(d, "/");
				d = custom_stringcat(d, string[1]);
			}
			else
			{
				d = custom_strdup(string[1]);
			}
		}
		ext_status = execute_cmd_cd(env, cur, d, string[1], number);
		free(d);
	}
	else
	{
		cd_home(env, cur);
	}
	free_dp(string);
	return (ext_status);
}
