#include "shell.h"

/**
 * _strdup - _strdup dupliacte function
 *
 * @org:  input for org
 *
 * Return: dup
 */

char *_strdup(char *org)
{
	int org_size;
	static char *dup;
	char *dup_offset;

	org_size = strlen(org);
	dup = (char *)malloc(sizeof(char) * org_size + 1);
	if (dup == NULL)
		return ((char *)NULL);

	dup_offset = dup;
	while (*org)
	{
		*dup_offset = *org;
		dup_offset++;
		org++;
	}
	*dup_offset = '\0';

	return (dup);
}

/**
 * _strcat - cat the string
 *
 * @destination: input for _strcat
 *
 * @source: input for the source
 *
 * @num: input for num
 *
 * Return: destination
 */

char *_strcat(char *destination, const char *source, size_t num)
{
	char  *ptr = destination + strlen(destination);

	while (*source != '\0' && num--)
		*ptr++ = *source++;
	*ptr = '\0';
	return (destination);
}
/**
 *printenv- function to print env
 *
 *Return: void
 */
void printenv(void)
{
	int i;
	size_t sl;

	i = 0;
	while (environ[i] != NULL)
	{
		sl = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], (sl + 1));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * pathString - pathString func
 *
 * Return: pathString
 */
char *pathString(void)
{
	int i = 0, j = 0;
	char **getPath, **ev;
	char *path = "PATH";

	ev = malloc(sizeof(char *) * 100);
	while (environ[j] != NULL)
	{
		ev[j] = strdup(environ[j]);
		j++;
	}
	getPath = _parseline(ev[i], "=");
	while (ev[i] != NULL)
	{
		getPath = _parseline(ev[i], "=");
		getPath = _parseline(NULL, ev[i]);
		if (_strcmp(ev[i], path) == 0)
		{
			free(ev);
			return (environ[i]);
		}
		i++;
	}
	free(ev);
	return (0);
}
