#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _strcmp - making our own string compare
 *
 * @str1: string 1
 *
 * @str2: string 2
 *
 * Return: _strcmp
 */
int _strcmp(char *str1, char *str2)
{
	if (*str1 < *str2)
		return (-1);
	if (*str1 > *str2)
		return (1);
	if (*str1 == '\0')
		return (0);

	return (_strcmp(str1 + 1, str2 + 1));
}

/**
 * _parseline - function to take string as input and break words up into tokens
 *and save in an array of strings
 *
 *@buf: string recieved
 *
 *@delim: delim
 *
 *Return: pointer to new arrary of strings
 */
char **_parseline(char *buf, char *delim)
{
	int i;
	char *tokens;
	char **args;

	i = 0;
	tokens = strtok(buf, delim);
	args = malloc(sizeof(char *));
	while (tokens)
	{
		args[i] = tokens;
		tokens = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}
/**
*_forkIt- function to create a child process and execute commands
*
*@str: string that contains command
*
*Return: void
*/
void _forkIt(char *str)
{
	char **gg;
	char *e = "exit\n";
	pid_t pid;
	int status = 0, er = 0;

	pid = fork();
	if (pid == 0)
	{
		gg = _parseline(str, " ");
		er = execve(gg[0], gg, NULL);
		if (er == -1)
		{
			perror("./shell: No such file or directory found");
			exit(1);
		}
	}
	if (pid > 0)
	{
		if (_strcmp(str, e) == 0)
		{
			exit(1);
		}
		wait(&status);
	}
}
