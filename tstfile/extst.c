#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int exchk;
	char *str;

	str = "/home/vagrant/simple_shell/tstfile/_which";

/*	if (ac < 2)
	{
		printf("Error in Usage\n");
		return (0);
	}*/
	av[0] = "./_which";

	exchk = execve(str, av, NULL);
	if (exchk < 0)
	{
		printf("Still need to learn\n");
		return (1);
	}
	return (0);
}
