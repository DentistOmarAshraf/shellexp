#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int x;

	x = access("ls", R_OK);
	printf("x = %d\n", x);

	return (0);

}
