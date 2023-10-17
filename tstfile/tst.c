#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	size_t i;
	struct stat buf;

/*	if (ac < 2)
	{
		printf("Error in use %s\n", av[0]);
		return (1);
	}*/

	for (i = 1 ; av[i] ; i++)
	{
		printf("av[%ld] = %s\n", i, av[i]);
		if (!(stat(av[i], &buf)))
			printf("Found\n");
		else
			printf("NO\n");
	}
	return (0);
}
