#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	int x; 
	struct stat st;

	x = stat("/bin/ls", &st);
	printf("stat(/bin/ls) === %d\n", x);
	x = stat("ls", &st);
	printf("stat(ls) === %d\n", x);

	return (0);
}
