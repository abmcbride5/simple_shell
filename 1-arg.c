#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
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

	l = 0;/*used for length of line recieved from input*/
	c = 0;/*used to hold number of characters recieved by getline*/
	buf = NULL;/*used to hold line*/
	write(STDOUT_FILENO, "$ ", 2);/*prints $ in terminal*/
	c = getline(&buf, &l, stdin);/*gets input from user*/
	write(STDOUT_FILENO, buf, c);/*prints input on newline*/
	free(buf);/*used to free memory allocated by getline*/
	return (c);/*number of charaters recieved*/
}
