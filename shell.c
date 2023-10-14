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
	int id, status, len2/*, glchk*/;

	while (1)
	{
		write(1, prom, _strlen(prom));
		/*ctrl + d  && exit work same but still there is some issue here*/
		if (getline(&input, &len, stdin) == -1 || _strcmp(input, "exit\n"))
		{
			if (input)
				free(input);
			break;
		}
		if (_strcmp(input, "\n"))
			continue;
		len2 = _strlen(input);
		input[len2 - 1] = '\0';
		argv = _argv(input);
		/* here we should know if the programme is there or not */
		id = fork();
		if (id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror(argv[0]);
			free_grid(argv);
			free_ptr(&input);
			return (0);
		}
		else
		{
			wait(&status);
			free_grid(argv);
		}
	}
	return (0);
}
