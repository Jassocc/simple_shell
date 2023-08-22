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
	char *prompt = "$ ", *line = NULL;
	size_t n = 0;
	ssize_t nc_read;
	const char *d = " \n";
	char *t, *arg[MAX_INPUT_SIZE];
	int a, should_exit = 0, *should_exit_ptr = &should_exit;

	(void)ac, (void)argv;
	while (!(*should_exit_ptr))
	{	my_printf("%s", prompt);
		nc_read = custom_getline(&line, &n, stdin);
			if (nc_read == -1)
			{	my_printf("Exiting...\n");
				free(line);
				break;
			}
		t = custom_strtok(line, d);
		a = 0;
		while (t != NULL && a < MAX_INPUT_SIZE - 1)
		{	arg[a] = t;
			a++;
			t = custom_strtok(NULL, d);	}
		arg[a] = NULL;
		if (arg[0] != NULL)
		{
			if (custom_strncmp(arg[0], "env", 3) == 0)
			{	custom_envbuiltin(arg, env);
			}
			else if (custom_strncmp(arg[0], "exit", 4) == 0)
			{
				exit_builtin(arg, should_exit_ptr);
			}
			/*else  if (custom_strncmp(arg[0], "setenv", 6) == 0)
			{
				execute_setenv(arg);
			}
			else if (custom_strncmp(arg[0], "unsetenv", 8) == 0)
			{
				execute_unsetenv(arg);
			}*/
			else
			{	execute_cmd(arg, custom_getenv);
			}
		}
		if (line != NULL)
		{	free(line);
			line = NULL; }
	} exit_shell(should_exit_ptr);
	return (0);
}
