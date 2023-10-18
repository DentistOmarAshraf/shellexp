#include <stdio.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", env);
	printf("%p\n", environ);

	return(0);
}
