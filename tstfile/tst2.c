#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	int read;

	while (1)
	{
		printf("prompt $ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
		return (0);
		if (read != -1 || (read == -1 && len > 0))
			;
	}

	return (0);
}
