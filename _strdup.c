#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * _strdup - _strdup dupliacte function
 *
 * @org:  input for org
 *
 * Return: dup
 */

char *_strdup(char *org)
{
	int org_size;
	static char *dup;
	char *dup_offset;

	org_size = strlen(org);
	dup = (char *)malloc(sizeof(char) * org_size + 1);
	if (dup == NULL)
		return ((char *)NULL);

	dup_offset = dup;
	while (*org)
	{
		*dup_offset = *org;
		dup_offset++;
		org++;
	}
	*dup_offset = '\0';

	return (dup);
}
