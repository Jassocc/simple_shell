#include "shell.h"

/**
 * main - main function for the shell
 * @ac: void
 * @argv: vector for arguments
 * Return: 0 if succes, -1 if fail
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *line;
	size_t n = 0;
	ssize_t nc_read;
	const char *d;
	char *t, *arg[MAX_INPUT_SIZE];
	int a;

	(void)ac;
	(void)argv;
	d = " \n";

	while (1)
	{
		my_printf("%s", prompt);
		nc_read = getline(&line, &n, stdin);
			if (nc_read == -1)
			{
				my_printf("Exiting...\n");
				return (0);
			}
		t = strtok(line, d);
		a = 0;
		while (t != NULL && a < MAX_INPUT_SIZE - 1)
		{
			arg[a] = t;
			a++;
			t = strtok(NULL, d);
		}
		arg[a] = NULL;
		if (arg[0] != NULL)
		{
			if (custom_strncmp(arg[0], "exit", 4) == 0)
			{
				exit_builtin(arg);
			}
			else
			{
				execute_cmd(arg, custom_getenv);
			}
		}
		if (line != NULL)
		{	free(line);
			line = NULL;
		}
	}
	return (0);
}
