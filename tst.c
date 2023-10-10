#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int _strcmp(char *, char *);
int _strlen(char *);
char **_argv(char *);
int count_words(char *s);

int main(void)
{
	char *prom = "$ ";
	char *ch1, *ch2;
	char *input = NULL;
	char **argv;
	size_t len = 0, len2;
	int i;

	while (1)
	{
		write(1, prom, _strlen(prom)); ;
		getline(&input, &len, stdin);
		len2 = _strlen(input);
		input[len2 - 1] = '\0';
		if (_strcmp(input, "exit"))
		{
			if (input)
				free(input);
			break;
		}
		printf("User Input : %s\n", input);
		argv = _argv(input);
		for (i = 0 ; argv[i] ; i++)
			printf("ch[%d] = %s len = %d\n", i, argv[i], _strlen(argv[i]));
	}
	return (0);
}
int count_words(char *s)
{
	int i, count;

	for (i = 0 ; s[i] ; i++)
	{
		if (i && s[i] == ' ' && s[i - 1] != ' ')
			count++;
	}
	if (s[i] == '\0' && s[i - 1] != ' ')
		count++;
	return (count);
}
char **_argv(char *str)
{
	int i, len;
	char **ret;
	int count;
	char *temp;

	count = count_words(str);
	ret = malloc(sizeof(char *) * count + 1);
	for (i = 0 ; i < count ; i++)
	{
		if (!i)
		{
			ret[i] = strtok(str, " ");
			continue;
		}
			ret[i] = strtok(NULL, " ");
	}
	ret[i] = NULL;
	return (ret);
}


int _strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	if (*s1 == *s2)
		return (_strcmp(s1 + 1, s2 + 1));
}
int _strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + _strlen(str + 1));
}
