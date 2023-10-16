#include "main.h"
#include <stdio.h>
/**
 * _strdup - copy str
 * helper function (replica of strdup)
 * @s: pointer to str
 * Return: pointer to str
 */
char *_strdup(const char *s)
{
	int len, i;
	char *ret;

	len = _strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (i = 0 ; s[i] ; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
/**
 * _getenv - function to get value of ceritin env var
 * replica of (getenv)
 * @name: pointer to str
 * Return: pointer to str
 */

char *_getenv(const char *name)
{
	int i;
	char *temp, *n , *cur, *ret;
	extern char **environ;

	n = _strdup(name);
	for (i = 0 ; environ[i] ; i++)
	{
		cur = _strdup(environ[i]);
		temp = strtok(cur, "=");
		if (_strcmp(n, temp))
		{
			ret = _strdup(strtok(NULL," "));
			free(n);
			free(temp);
			return (ret);
		}
		free(temp);
	}
	return (NULL);
}
