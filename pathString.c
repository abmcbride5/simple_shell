#include <stdio.h>
#include "shell.h"
#include <string.h>
extern char **environ;
char *pathString(void)
{
	int i = 0, j = 0;
	char **getPath, **ev;
	char *path = "PATH";

	ev = malloc(sizeof(char*) *100);
	while (environ[j] != NULL)
	{
		ev[j] = strdup(environ[j]);
		j++;
	}
	getPath = _parseline(ev[i], "=");
	while(ev[i] != NULL)
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
