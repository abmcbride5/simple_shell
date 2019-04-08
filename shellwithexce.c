#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
int main(void)
{
	char *buf;
	char *e = "exit\n";
	char *gg[] = {"", NULL};
	size_t l;
	ssize_t c;
	pid_t pid;
	int status;




	l = 0;
	c = 0;
	while (1)
	{
		buf = NULL;
		write(STDOUT_FILENO, "$ ", 2);
		c = getline(&buf, &l, stdin);
		if (strcmp(buf, e) ==0)
		{
			exit (1);
		}
		buf[c-1] = '\0';
		if (c > 1)
		{
			pid = fork();
			if (pid == 0)
			{
				if (_strcmp(buf, e) == 0)
					exit (1);
				write(STDOUT_FILENO, buf, c);
				execve(buf, gg, NULL);
			}
			if (pid > 0)
			{
				  if (strcmp(buf, e) == 0)
				  {
				  exit (1);
				  }
				wait(&status); 
					
			}

		}
	}
	free(buf);
	return(c);
}
