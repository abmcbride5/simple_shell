#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

/*int main(__attribute__((unused)) int argc, char *argv[]);*/
int _strcmp(char *str1, char *str2);
int _putchar(char c);

#endif
=======
char **_parseline(char *buf);
int _strcmp(char *str1, char *str2);
int _putchar(char c);
#endif /*SHELL_H*/
>>>>>>> 2db1c4c3a933e56db74ac6067c26cfaea77bfd4e
