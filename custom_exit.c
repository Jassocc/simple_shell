#include "shell.h"

/**
 * exit_builtin - custom exit function
 * @command: cmd argument
 */
void exit_builtin(char *command[])
{
	int status = 0;

	if (command[1] != NULL)
	{
		status = custom_atoi(command[1]);
		if (status == -1)
		{
			perror("Invalid exit status");
			return;
		}
		my_printf("Exititng...\n");
		exit(status);
	}
	else
	{
		my_printf("Exiting...\n");
		exit(0);
	}
}
