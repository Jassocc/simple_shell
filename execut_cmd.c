#include "shell.h"

/**
 * execute_cmd - executes command from user input
 * @command: cmd to be executed
 */
void execute_cmd(char *command[])
{
	char cmd_path[MAX_INPUT_SIZE];

	_stringcat(cmd_path, sizeof(cmd_path), "/usr/bin/");
	_stringcat(cmd_path, sizeof(cmd_path), command[0]);

	if (fork() == 0)
	{
		execve(cmd_path, command, NULL);
		perror("Error");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
