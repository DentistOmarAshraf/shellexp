#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strcmp(char *, char *);
int _strlen(char *);
char **_argv(char *);
int count_words(char *);
char *_strcat(char *, char *);
void free_grid(char **);
void free_ptr(char **);
#endif
