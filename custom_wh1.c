#include "shell.h"

/**
 * custom_wh - appending to a matching PATH
 * @string: first cmd
 * @env: environment
 * Return: cmd
 */
char *custom_wh(char *string, list_t *env)
{
	char *p, *c = NULL, **token;
	int a = 0;

	p = custom_look_env("PATH", env);
	token = cust_tok(p, ":");
	free(p);
	a = 0;
	while (token[a] != NULL)
	{
		if (token[a][0] == '\0')
		{
			c = getcwd(c, 0);
		}
		else
		{
			c = custom_strdup(token[a]);
		}
		c = custom_stringcat(c, "/");
		c = custom_stringcat(c, string);
		if (access(c, F_OK) == 0)
		{
			free_dp(token);
			return (c);
		}
		free(c);
		a++;
	}
	free_dp(token);
	return (string);
}
