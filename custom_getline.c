#include "shell.h"

/**
 * custom_getline - custom implementation of getline
 * @linep: pointer to buffer
 * @n: pointer to size
 * @stream: input
 * Return: number of chars
 */
ssize_t custom_getline(char **linep, size_t *n, FILE *stream)
{
	size_t size = 0;
	ssize_t i = 0, j;
	char buffer[MAX_INPUT_SIZE];

	(void)stream, (void)n;
	while ((i = read(STDIN_FILENO, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[i] = '\0';
		*linep = custom_realloc(*linep, size + i + 1);
		if (*linep == NULL)
		{
			perror("Error: Memory allocation failed");
			return (-1);
		}
		custom_memcpy(*linep + size, buffer, i + 1);
		size = size + i + 1;
		for (j = 0; j < i; j++)
		{
			if (buffer[j] == '\n')
			{
				size++;
				break;
			}
		}
		if (buffer[i - 1] == '\n')
		{
			break;
		}
	}
	if (i == 0 && size == 0)
	{
		return (-1);
	}
	return (size + 1);
}
