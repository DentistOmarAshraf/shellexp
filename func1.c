#include "main.h"

int _strlen(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen(s + 1));
}

int _strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	return (_strcmp(s1 + 1, s2 + 1));
}

int count_words(char *s)
{
	int i, count;

	for (i = 0 ; s[i] ; i++)
		if (i && s[i] == ' ' && s[i - 1] != ' ')
			count++;
	if (s[i] == '\0' && s[i] != ' ')
		count++;
	return (count);
}

char **_argv(char *s)
{
	int i, count;
	char **ret;

	count = count_words(s);
	ret = malloc(sizeof(char *) * (count));
	if (!ret)
		exit(98);
	for (i = 0 ; i < count ; i++)
	{
		if (!i)
		{
			ret[i] = strtok(s, " ");
			continue;
		}
		ret[i] = strtok(NULL, " ");
	}
	ret[i] = NULL;
	return (ret);
}
char *_strcat(char *s1, char *s2)
{
	char *all;
	int len1, len2, i, j;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	all = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!all)
		exit(98);
	for (i = 0 ; s1[i] ; i++)
		all[i] = s1[i];
	for (j = 0 ; s2[j] ; j++)
		all[i++] = s2[j];
	all[i] = '\0';
	return (all);
}
