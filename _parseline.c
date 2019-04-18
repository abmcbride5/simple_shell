#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
/**
*function to take string as input and break words up into tokens 
*and save in an array of strings
*
*@buf - string recieved
*@delim - delim
*
*Return- pointer to new arrary of strings
*/
char **_parseline(char *buf, char *delim)
{
	int i, c;
	char *tokens;
	char **args;
	char *buffer;

	buffer = buf;
	i = 0;
	tokens = strtok(buf, delim);
	c = _counter(buffer, delim);
	args = malloc(sizeof(char*) * (c + 1));
	while(tokens)
	{
		args[i] = tokens;
		tokens = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	free(args);
	return (args);
}
