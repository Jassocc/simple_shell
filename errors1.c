#include "shell.h"

/**
 * cannot_change - error
 * @string: argument
 * @num: number arg
 * @env: var
 */
void cannot_change(char *string, int num, list_t *env)
{
	int c = 0;
	char *sh, *numbo;

	sh = custom_look_env("_", env);
	while (sh[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, sh, c);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	numbo = int_transfer(num);
	c = 0;
	while(numbo[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, numbo, c);
	free(numbo);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	c = 0;
	while (string[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, string, c);
	write(STDOUT_FILENO,  "\n", 1);
}
/**
 * invalid_num - write error
 * @string: string
 * @num: arg num
 * @env: env var
 */
void invalid_num(char *string, int num, list_t *env)
{
	int c = 0;
	char *sh = NULL, *numbo = NULL;

	sh = custom_look_env("_", env);
	while (sh[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, sh, c);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	numbo = int_transfer(num);
	c = 0;
	while (numbo[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, numbo, c);
	free(numbo);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	c = 0;
	while (string[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, string, c);
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * havent_found - error
 * @string: cmd
 * @num: n cmd
 * Return: env var
 */
void havent_found(char *string, int num, list_t *env)
{
	int c = 0;
	char *sh, *numbo;

	sh = custom_look_env("_", env);
	while (sh[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, sh, c);
	free(sh);
	write(STDOUT_FILENO, ": ", 2);
	numbo = int_transfer(num);
	c = 0;
	while (numbo[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, numbo, c);
	free(numbo);
	write(STDOUT_FILENO, ": ", 2);
	c = 0;
	while (string[c] != '\0')
	{
		c++;
	}
	write(STDOUT_FILENO, string, c);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
