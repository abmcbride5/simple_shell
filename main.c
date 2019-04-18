#include <stdio.h>
#include "shell.h"

int main(void)
{
	char *gg, *token, **ll, **ns;
	int i = 0, j = 0;

	ns = malloc(sizeof(char*) * 20);
	ll = malloc(sizeof(char*) * 100);
	gg = malloc(sizeof(char*) * 20);
	gg = pathString();
	token = strtok(gg, "=:");
	while(token)
	{
		ll[i] = malloc(sizeof(char) * _strlen(token));
		ll[i] = token;
		token = strtok(NULL, "=:");
		_strcat(ll[i], "/");
		printf("%s\n", ll[i]);
		i++;
	}
/*	while(ll[j] != NULL)
	{
		printf("%s\n", ll[j]);
		_strcat(ll[j], "ls");
		//printf("%s\n", ll[j]);
		j++;
	}*/
	return (0);
}
