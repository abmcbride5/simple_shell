#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
*main- program to print a $ and wait to recieve input
*
*Return: number of character input
*/

/**
*This was part of the everything you need to know about building a simple shell resource. this is ex.2 of the argument section
*/
int main(void)
{
	char *buf;
	size_t l, c;
	pid_t pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/usr", NULL};

	l = 0;/*used for length of line recieved from input*/
	c = 0;/*used to hold number of characters recieved by getline*/
	buf = NULL;/*used to hold line*/
	write(STDOUT_FILENO, "$ ", 2);/*prints $ in terminal*/
	c = getline(&buf, &l, stdin);/*gets input from user*/
	if (c > 1)/*if there is input fork*/
	{
		pid = fork();
		if(pid == 0)/*if child process*/
		{
			execve(argv[0], argv, NULL);
			/**
			*the current code prints list
			*no matter what is entered into
			*prompt line. this was a test
			*there needs to be additional
			*code added here that will do 
			*the work of the shell
			*/
		}
		else if (pid > 0)/*if parent process wait for child*/
		{
			wait(&status);
		}
	}
	else/*if fork did not occur*/
	{
		write(STDOUT_FILENO, "No data entered\n", 16);
	}
	free(buf);/*used to free memory allocated by getline*/
	printf("%zu\n", c);/*this will print number of characters*/
	return (c);/*number of charaters recieved*/
}
