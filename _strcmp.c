#include <unistd.h>

/**
 * _strcmp - making our own string compare
 *
 * @str1: string 1
 *
 * @str2: string 2
 */
int _strcmp(char *str1, char *str2)
{
	if (*str1 < *str2)
		return -1;
	if (*str1 > *str2)
		return 1;
	if (*str1 == '\0')
		return 0;

	return _strcmp(str1 + 1, str2 + 1);
}
