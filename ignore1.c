#include "shell.h"

/**
 * contc - ignore control c
 * @i: int from sig
 */
void contc(int i)
{
	(void)i;

	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * no_space - ignore spaces
 * @string: string
 * Return: new string
 */
char *no_space(char *string)
{
	while (*string == ' ')
	{
		string++;
	}
	return (string);
}
/**
 * contd - eof
 * @i: chars read
 * @cmd: command
 * @envir: environment
 */
void contd(int i, char *cmd, list_t *env)
{
	if (i == 0)
	{
		free(cmd);
		free_list(env);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
}
