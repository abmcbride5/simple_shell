#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
*main - program that takes a string and parses it into tokens
*
*Return: number of characters recieved variable size_t c
*/
/**
*I tried to make this program using argc and argv but I kept getting
*incorrect output for the tokens and strings where not being properly
*parsed through to produce the correct number of tokens.
*so I ended up adding the prompt code from ex1 in the arguments
*section
*/
int main(void)
{
	size_t l, c;
	char *tokens;/*where tokens will be stored*/
	char *str;
	/**
	*going to use getline and this is where the line
	* will be stored
	*/
	l = 0;/*used for length of str*/
	c = 0;/*used to store number of characters recieved*/
	str = NULL;/*used to hold string to be parsed into tokens*/
	write(STDOUT_FILENO, "ENTER STRING$ ", 15);
	c = getline(&str, &l, stdin);
	/**
	*the above portion will create a prompt that will recieve
	*the string to be parsed
	*/
	tokens = strtok(str, "  ,-\"\n\t");
	/*stores tokens into pointer*/
	/**
	*the delimiter portion uses everything in quotes
	*to distingush between tokens.
	*/
	while (tokens != NULL)
	/**
	*loop to print out all tokens(this is a
	*check to help me make sure the program is
	*functioning properly. it will probably be taken
	*out later
	*/
	{
		printf("token: %s\n", tokens);
		tokens = strtok(NULL, "  ,-");
		/**
		*I tried doing the loop without this line
		*and ended up with an infinite loop. it seems
		* this line puts the null byte at the end of
		*the new token.
		*/
	}
	return (c);
}
