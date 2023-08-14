#include "shell.h"

/**
 * execute_cmd - executes command from user input
 * @command: cmd to be executed
 * @custom_getenv: custom getenv
 */
void execute_cmd(char *command[], char *(*custom_getenv)(const char *))
{
	char cmd_path[MAX_INPUT_SIZE];
	char *path = custom_getenv("PATH");
	char *path_cpy, *token;

	if (!path)
	{
		perror("Error: PATH environment variable not set");
		return;
	}
	if (command[0][0] == '/')
	{
		execute_absolute_path(command);
		return;
	}
	path_cpy = c_strdup(path);
	token = strtok(path_cpy, ":");
	while (token != NULL)
	{
		cmd_path[0] = '\0';
		_stringcat(cmd_path, sizeof(cmd_path), token);
		_stringcat(cmd_path, sizeof(cmd_path), "/");
		_stringcat(cmd_path, sizeof(cmd_path), command[0]);
		if (access(cmd_path, X_OK) == 0)
		{
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
			free(path_cpy);
			return;
		}
		token = strtok(NULL, ":");
	} free(path_cpy);
	my_printf("Command not found: %s\n", command[0]);
}
/**
 * execute_absolute_path - executes absolute cmds
 * @command:cmd
 */
void execute_absolute_path(char *command[])
{
	if (access(command[0], X_OK) == 0)
	{
		if (fork() == 0)
		{
			execve(command[0], command, NULL);
			perror("Error");
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		my_printf("Command not found: %s\n", command[0]);
	}
}


