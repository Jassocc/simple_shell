#include "shell.h"

/**
 * custom_getline - custom implementation of getline
 * @streamer: input
 * Return: number of chars
 */
size_t custom_getline(char **streamer)
{
	ssize_t a = 0, tok1 = 0, tok2 = 0, numbo = 0;
	static char buffer[1024];
	static ssize_t buff_s = 0;

	while (tok2 == 0 && (a = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (a == -1)
		{
			return (-1);
		}
		if (a == 0 && buff_s == 0)
			break;
		buffer[buff_s + a] = '\0';
		while (numbo < buff_s + a)
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
			buff_s = a;
			tok1 = 1;
		}
		else
		{
			buff_s = buff_s + a;
			*streamer = custom_stringcat(*streamer, buffer);
		}
	}
	return (buff_s);
}
