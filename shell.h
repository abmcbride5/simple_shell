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

int _putchar(char c);
char **_parseline(char *buf, char *delim);
int _strcmp(char *str1, char *str2);
int _putchar(char c);
char *pathString(void);
void _forkIt(char *str);
int _counter(char *buf, char *delim);
char **parsePath(void);
int _strlen(char *s);
void printenv(void);
char *_strdup(char *org);
char *_strcat(char *destination, const char *source, size_t num);
extern char **environ;

#endif
