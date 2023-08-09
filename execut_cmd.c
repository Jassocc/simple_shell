#include "shell.h"

/**
 * execute_cmd - executes command from user input
 * @command: cmd to be executed
 */
void execute_cmd(const char *command)
{
	char *args[MAX_INPUT_SIZE];
	char cmd_path[MAX_INPUT_SIZE];

	_stringcat(cmd_path, sizeof(cmd_path), "/usr/bin/");
	_stringcat(cmd_path, sizeof(cmd_path), command);

	args[0] = cmd_path;
	args[1] = NULL;
	args[2] = NULL;

	if (fork() == 0)
	{
		execve(args[0], args, NULL);
		perror("Error");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
