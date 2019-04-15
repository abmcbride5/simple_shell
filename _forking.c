#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
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
