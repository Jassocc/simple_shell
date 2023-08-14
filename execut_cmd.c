#include "shell.h"

/**
 * execute_cmd - executes command from user input
 * @command: cmd to be executed
 */
void execute_cmd(char *command[])
{
	char cmd_path[MAX_INPUT_SIZE];
	char *path = getenv("PATH");
	char *path_cpy, *token;

	if (!path)
	{
		perror("Error: PATH environment variable not set");
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
		printf("Trying command: %s\n", cmd_path);
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
	}
	free(path_cpy);
	my_printf("Command not found: %s\n", command[0]);
}
