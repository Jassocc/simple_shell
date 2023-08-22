#include "shell.h"

/**
 * custom_getline - custom implementation of getline
 * @streamer: input
 * Return: number of chars
 */
size_t custom_getline(char **streamer)
{
	ssize_t a = 0, s = 0, tok1 = 0, tok2 = 0, numbo = 0;
	char buffer[1024];

	while (tok2 == 0 && (a = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (a == -1)
		{
			return (-1);
		}
		buffer[a] = '\0';
		while (buffer[numbo] != '\0')
		{
			if (buffer[numbo] == '\n')
			{
				tok2 = 1;
			}
			numbo++;
		}
		if (tok1 == 0)
		{
			a++;
			*streamer = malloc(sizeof(char) * a);
			*streamer = custom_strcopy(*streamer, buffer);
			s = a;
			tok1 = 1;
		}
		else
		{
			s = s + a;
			*streamer = custom_stringcat(*streamer, buffer);
		}
	}
	return (s);
}
