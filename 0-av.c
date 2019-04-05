#include <stdio.h>
#include <unistd.h>
/**
*main- program to print all arguments withut using argc.
*
*@argc: number of arguments
*@argv: array of arguments
*
*Return: 0
*/
/**
*this is form the everything you need to know about building a simple shell, the arguments section.
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	int i;

	i = 0;
	while (argv[i])
	{
		write(STDOUT_FILENO, argv[i], 10);
		write(STDOUT_FILENO, "\n", 1);
		/*printf("pf %s\n", argv[i]);*/
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
