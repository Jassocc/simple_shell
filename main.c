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
	char *t;
	int a;

	(void)ac;
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
		argv = malloc(sizeof(char *) * MAX_INPUT_SIZE);
		t = strtok(line, d);
		for (a = 0; t != NULL; a++)
		{
			argv[a] = malloc(custom_strlen(t) + 1);
			strcopy(argv[a], t);
			t = strtok(NULL, d);
		}
		argv[a] = NULL;
		execute_cmd(argv[0]);
		for (a = 0; argv[a] != NULL; a++)
		{	free(argv[a]);
		}
		free(argv);
		if (line != NULL)
		{	free(line);
			line = NULL;
		}
	}
	return (0);
}
