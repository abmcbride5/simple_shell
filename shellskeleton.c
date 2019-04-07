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
	/*the char array below is where the exec func is getting it's path to execute*/
	char *argv[] = {"/bin/ls", "-l", "/home/vagrant/simple_shell/", NULL};

	l = 0;/*used for length of line recieved from input*/
	c = 0;/*used to hold number of characters recieved by getline*/
	/**
	*I think the below code needs to be in a loop.
	*I could be wrong but that is the only way I can think to
	*get the prompt to keep repeating. I could be wrong
	*/
	buf = NULL;/*used to hold line*/
	while(1)
	{
		write(STDOUT_FILENO, "$ ", 2);/*prints $ in terminal*/
		c = getline(&buf, &l, stdin);/*gets input from user*/
		if (strcmp(buf, e) == 0)
		{
			break;
		}

		if (c > 1)/*if there is input fork*/
		{

			pid = fork();/*this is where the fork happens*/
			if(pid == 0)/*if child process*/
			{
				if (strcmp(buf,e) == 0)
				{
					break;
				}
				write(STDOUT_FILENO, buf, c);
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
			wait(&status);/*tells parent to wait until child is finished*/
			if (strcmp(buf, e) == 0)
			{
				break;
			}

		}
		}
	}
	else/*if fork did not occur*/
	{
		write(STDOUT_FILENO, "No data entered\n", 16);
	}
	free(buf);/*used to free memory allocated by getline*/
	printf("%ld\n", (long)c);/*this will print number of characters*/
	return(c);/*number of characters recieved*/
}
