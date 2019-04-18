#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
/**
*main - program that creates a prompt, recieves input and calls
*forking function when needed.
*
*Return: void
*/
int main(void)
{
	char *buf = NULL;
	char *e = "exit\n";
	size_t l = 0;
	ssize_t c = 0;
	char *env = "env\n";

	while (1)
	{
		write(STDOUT_FILENO,"$ ", 2);
		c = getline(&buf, &l, stdin);
		if (c == -1)
		{
			exit(1);
		}
		if (_strcmp(buf, e) == 0)
		{
			exit(1);
		}
		if (_strcmp(buf, env) == 0)
			printenv();
		else if (c > 1)
		{
			buf[c - 1] = '\0';
			_forkIt(buf);
		}
	}
	return (0);
}
