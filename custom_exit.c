#include "shell.h"

/**
 * exit_builtin - custom exit function
 * @command: cmd argument
 */
void exit_builtin(char *command[])
{
	(void)command;

	my_printf("Exititng...\n");
	exit(0);
}
