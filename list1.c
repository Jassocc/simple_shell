#include "shell.h"

/**
 * my_printf - print list
 * @liced: list
 * Return: size
 */
size_t my_printf(list_t *liced)
{
	list_t *counter = liced;
	int append = 0, cas = 0;

	if (liced == NULL)
	{
		return (0);
	}
	while (counter != NULL)
	{
		if (counter->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			cas = 0;
			while ((counter->var)[cas] != '\0')
			{
				cas++;
			}
			write(STDOUT_FILENO, counter->var, cas);
			write(STDOUT_FILENO, "\n", 1);
		}
		counter = counter->next;
		append++;
	}
	return (append);
}
/**
 * node_ended - end node
 * @top: pointer to start
 * @n_data: data to new node
 * Return: pointer
 */
list_t *node_ended(list_t **top, char *n_data)
{
	list_t *n, *hol;

	if (top == NULL || n_data == NULL)
	{
		return (NULL);
	}
	n = malloc(sizeof(list_t));
	if (n == NULL)
	{
		return (NULL);
	}
	n->var = custom_strdup(n_data);
	n->next = NULL;
	hol = *top;
	if (hol != NULL)
	{
		while (hol->next != NULL)
		{
			hol = hol->next;
		}
		hol->next = n;
	}
	else
	{
		*top = n;
	}
	return (*top);
}
/**
 * idx_node - remove node at index
 * @top: head adrress
 * @idx: index
 * Return: 1
 */
int idx_node(list_t **top, int idx)
{
	list_t *starting, *hol;
	int counter = 0;

	if (*top == NULL)
	{
		return (-1);
	}
	if (idx == 0)
	{
		hol = (*top)->next;
		free((*top)->var);
		free(*top);
		*top = hol;
		return (1);
	}
	counter = 1;
	starting = *top;
	while (counter < idx)
	{
		if (starting == NULL)
		{
			return (-1);
		}
		starting = starting->next;
		counter++;
	}
	hol = starting->next;
	starting->next = hol->next;
	free(hol->var);
	free(hol);
	return (1);
}
/**
 * free_list - frees list
 * @listings: list
 */
void free_list(list_t *listings)
{
	list_t *hol;

	while (listings != NULL)
	{
		hol = listings;
		listings = listings->next;
		free(hol->var);
		free(hol);
	}
}
