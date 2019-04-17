#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * _strcat - cat the string
 *
 * @destination: input for _strcat
 *
 * @source: input for the source
 *
 * @num: input for num
 *
 * Return: destination
 */

char *_strcat(char *destination, const char *source, size_t num)
{
	char  *ptr = destination + strlen(destination);

	while (*source != '\0' && num--)
		*ptr++ = *source++;
	*ptr = '\0';
	return (destination);
}
