#include "main.h"
/**
 * _strlen - to messure string length
 * @s: pointer to str
 * Return: int (length of str)
 */
int _strlen(const char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen(s + 1));
}
/**
 * _strcmp - function to compare to str
 * used this function to compare user order
 * if 'exit' break the loop
 * @s1: pointer to str
 * @s2: pointer to str
 * Return: 1 if identicar
 */
int _strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	return (_strcmp(s1 + 1, s2 + 1));
}
/**
 * count_words - function to count how many word in str
 * despite if there is many spaces - func helper to _argv
 * @str: pointer to str
 * Return: int (count of words)
 */
int count_words(char *str)
{
	int i, spc;

	spc = 0;
	for (i = 0 ; str[i] ; i++)
	{
		if (i && str[i] == ' ' && str[i - 1] != ' ')
			spc++;
	}
	if (str[i] == '\0' && str[i - 1] != ' ')
		spc++;
	return (spc);
}
/**
 * _argv - func to make str array of pointer of str
 * null terminated 'replica of strtok'
 * @str: pointer to str
 * Return: pointer of pointer of str
 */
char **_argv(char *str)
{
	char **new;
	int words, i, j, count, count2;

	if (str == NULL || count_words(str) == 0 || _strlen(str) == 0)
		return (NULL);
	words = count_words(str);
	printf("%d\n", words);
	new = malloc(sizeof(char *) * (words + 1));
	if (new == NULL)
		return (NULL);

	count = 0;
	count2 = 0;
	for (i = 0 ; i < words ; i++)
	{
		while (str[count] == ' ')
			count++;
		for (j = 0 ; str[count] != ' ' && str[count]; j++, count++)
			;
		new[i] = malloc(sizeof(char) * (j + 1));
			if (!new)
			{
				for (i = 0 ; i < words ; i++)
					free(new[i]);
				free(new);
				return (NULL);
			}
		while (str[count2] == ' ')
			count2++;
		for (j = 0 ; str[count2] != ' ' && str[count2] ; j++, count2++)
			new[i][j] = str[count2];
		new[i][j] = '\0';
	}
	new[i] = NULL;
	return (new);
}
/**
 * _strcat - function used to concatet to str
 * @s1: first pointer to str
 * @s2: seconed pointer to str
 * Return: pointer to str
 */
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
