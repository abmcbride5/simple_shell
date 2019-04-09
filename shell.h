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

/*int main(__attribute__((unused)) int argc, char *argv[]);*/
int _strcmp(char *str1, char *str2);
int _putchar(char c);
char **_parseline(char *buf);
 /*SHELL_H*/
#endif
