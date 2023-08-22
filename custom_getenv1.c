#include "shell.h"

/**
 * custom_duplicate - duplication
 * @string: string to dup
 * @bytes: num of bytes
 * Return: string
 */
char *custom_duplicate(char *string, int bytes)
{
	char *dup;
	int a, b;

	b = 0;
	if (string == NULL)
	{
		return (NULL);
	}
	while (*(string + b))
	{
		b++;
	}
	b++;
	dup = malloc(sizeof(char) * (b - bytes));
	if (dup == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (a < (b - bytes))
	{
		*(dup + a) = *(string + bytes + a);
		a++;
	}
	return (dup);
}
/**
 * custom_getenv - implementation of getenv
 * @name: eviron var name
 * @env: env vasriables
 * Return: value
 */
char *custom_look_env(char *name, list_t *env)
{
	int dif = 0, bytes = 0;

	while (env != NULL)
	{
		dif = 0;
		while ((env->var)[dif] == name[dif])
		{
			dif++;
		}
		if ((name[dif] == '\0') && (env->var)[dif] == '=')
		{
			break;
		}
		env = env->next;
	}
	while (name[bytes] != '\0')
	{
		bytes++;
	}
	bytes++;
	return (custom_duplicate(env->var, bytes));
}
