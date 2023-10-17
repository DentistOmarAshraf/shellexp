#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls","-l", NULL};

	execve("/bin/ls", argv, NULL);

	return (0);
}
