#include "main.h"
/**
 * main - Entry point (shell)
 * @ac: number of argments
 * @av: 2d array argments
 * @env: environment
 * Return: Alwyas 0
 */

int main(int ac, char **av, char **env)
{
	char *prom = "$ ", /* *dir,*/ *input = NULL;
	size_t len = 0;
	int id, status/*, glchk*/, exchk;

	while (true)
	{
		chkatt(prom);
		if (getline(&input, &len, stdin) == -1 || _strcmp(input, "exit\n"))
		{
			free_ptr(&input);
			break;
		}
		if (_strcmp(input, "\n"))
			continue;
		inpmod(&input);
		if (ac < 2)
		{
			av = _argv(input);
			if (!av)
				continue;
		}
		if (_strcmp(av[0], "exit"))
			break;
		id = fork();
		if (id == 0)
		{
			exchk = execve(av[0], av, env);
			if (exchk == -1)
				perror(av[0]);
			free_ptr(&input);
			free_grid(av);
			return (0);
		}
		else
		{
			waitpid(id, &status, 0);
			free_ptr(&input);
			free_grid(av);	}
	}
	return (0);
}
