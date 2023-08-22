#include "shell.h"

/**
 * free_dp - free arrays
 * @arr: array
 */
void free_dp(char **arr)
{
	int string;

	string = 0;
	while (arr[string] != NULL)
	{
		free(arr[string]);
		string++;
	}
	free(arr);
}
