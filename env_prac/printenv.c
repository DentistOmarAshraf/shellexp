#include <stdio.h>

int main(int ac, char **av, char **env)
{
	int i;

	for (i = 0 ; env[i] ; i++)
	{
		printf("%s\n", env[i]);
		printf("_____\n");
	}

	return (0);
}
