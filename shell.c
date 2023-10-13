#include "main.h"
/**
 * main - Entry point (shell)
 * Return: Alwyas 0
 */

int main(void)
{
	char *prom = "$ ", /* *dir,*/ *input = NULL;
	char **argv;
	size_t len = 0;
	int id, status, len2, glchk;

	while (1)
	{
		write(1, prom, _strlen(prom));
		glchk = getline(&input, &len, stdin);
		if (_strcmp(input, "\n"))
			continue;
		len2 = _strlen(input);
		input[len2 - 1] = '\0';
		if (_strcmp(input, "exit") || glchk < 0)
		{
			if (input)
				free(input);
			break;	}
		argv = _argv(input);
		id = fork();
		if (id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(argv[0]);
				free_grid(argv);
				free(input);
				return (1);	}
			if (input)
				free(input);
			free_grid(argv);
		}
		else
		{
			if (argv)
				free_grid(argv);
			waitpid(id, &status, 0);	}

	}
	return (0);
}
