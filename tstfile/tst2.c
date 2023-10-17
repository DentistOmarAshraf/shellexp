#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdlib.h>
char *_strcat(char *s1, char *s2)
{
	int len1, len2, i, j;
	char *new;

	for (len1 = 0 ; s1[len1] ; len1++)
		;
	for (len2 = 0 ; s2[len2] ; len2++)
		;
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	for (i = 0 ; s1[i] ; i++)
		new[i] = s1[i];
	for (j = 0 ; s2[j] ; j++)
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}

int main(int ac, char **av)
{
	int i;
	struct stat st;
	char *path, *temp;
	char buf[100];

	printf("%s\n", av[0]);
	if (ac < 2)
	{
		printf("Usage: _which file name\n");
		return (0);
	}
	i = 1;
	path = getcwd(buf, 100);
	while (av[i])
	{
		temp = _strcat(path,av[i]);
		if (stat(temp, &st) == 0)
			printf("av[%d] is %s Is here\n", i, av[i]);
		else
			printf("Its NOT here\n");
		free(temp);
		i++;
	}

	return (0);
}
