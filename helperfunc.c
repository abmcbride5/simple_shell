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
	args = malloc(sizeof(char *) * 1024);
	{
	if (args == NULL)
		return (0);
	}
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
	pid_t pid;
	int status = 0, er = 0;

	pid = fork();
	if (pid == 0)
	{
		gg = _parseline(str, " ");
		er = execve(gg[0], gg, environ);
		if (er == -1)
		{
			write(STDERR_FILENO, gg[0], _strlen(gg[0]));
			write(STDERR_FILENO, ": No such file or directory found \n", 36);
			free(gg);
			free(str);
			exit(0);
		}
	}
	if (pid > 0)
	{
		wait(&status);
	}
}
/**
*_counter - function to count how many words a string has
*
*@buf: string to be parsedd
*@delim: delimiter used
*
*Return: number of words parsed
*/
int _counter(char *buf, char *delim)
{
	int count;
	char *tokens;

	count = 1;
	tokens = strtok(buf, delim);
	while (tokens)
	{
		count++;
		tokens = strtok(NULL, delim);
	}
	return (count);
}
/**
*_strlen- function to calculate the length of a string
*
*@s: given string
*
*Return: length of string
*/
int _strlen(char *s)
{
	int r = 0;

	while (s[r] != '\0')
	{
		r++;
	}
	return (r);
}
