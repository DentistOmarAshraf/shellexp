#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

int _strcmp(char *, char *);
int _strlen(const char *);
char *_strdup(const char *);
char **_argv(char *);
int count_words(char *);
char *_strcat(char *, char *);
char *_getenv(const char *);
void free_grid(char **);
void free_ptr(char **);

#endif
