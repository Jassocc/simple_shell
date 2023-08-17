#include "shell.h"

/**
 * custom_memcpy - custom memory copy
 * @des: destination
 * @sr: source
 * @n: num of bytes
 */
void custom_memcpy(void *des, const void *sr, size_t n)
{
	char *d = (char *)des;
	const char *s = (const char *)sr;
	size_t i;

	for (i = 0; i < n; i++)
	{
		d[i] = s[i];
	}
}
