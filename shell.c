#include "main.h"
/**
 * main - Entry point (shell)
 * Return: Alwyas 0
 */

int main(void)
{
	char *prom = "$ ", *dir;
	char *input = NULL;
	char **argv;
	size_t len = 0;
	int id, status, len2;

	while (1)
	{
		write(1, prom, _strlen(prom));
		getline(&input, &len, stdin);
		len2 = _strlen(input);
		input[len2 - 1] = '\0';
		if (_strcmp(input, "exit"))
		{
			if (input)
				free(input);
			break;
		}
		argv = _argv(input);
		dir = _strcat("/bin/", argv[0]);
		id = fork();
		if (id == 0)
		{
			if (execve(dir, argv, NULL) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else if (id < 0)
			perror("forking error\n");
		else
			waitpid(id, &status, 0);
	}
	return (0);
}
