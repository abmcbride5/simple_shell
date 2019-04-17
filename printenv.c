#include "shell.h"
/**
*printenv- function to print env
*
*Return: void
*/
extern char **environ;
void printenv(void)
{
	int i;
	size_t sl;

	i = 0;
	while (environ[i] != NULL)
	{
		sl = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], (sl + 1)); 
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
