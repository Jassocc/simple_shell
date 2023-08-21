#include "shell.h"

/**
 * exit_builtin - custom exit function
 * @command: cmd argument
 * @should_exit_ptr: exit flag
 */
void exit_builtin(char *command[], int *should_exit_ptr)
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
		exit_shell(should_exit_ptr);
		exit(status);
	}
	else
	{
		my_printf("Exiting...\n");
		/*exit(0);*/
		exit_shell(should_exit_ptr);
	}
}
/**
 * exit_shell - function to exit shell
 * @should_exit_ptr: pointer
 * Return: 0
 */
int exit_shell(int *should_exit_ptr)
{
	*should_exit_ptr = 1;
	return (0);
}
