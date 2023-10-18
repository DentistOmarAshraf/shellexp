#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *input = NULL;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	else
		printf("Not connected\n");

	getline(&input, &len, stdin);
	
	printf("%s", input);

	return (0);
}
