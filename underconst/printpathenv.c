#include <stdio.h>
#include <string.h>
#include "main.h"

int main(void)
{
	char *path, *temp;
	int i;

	path = _getenv("PATH");
	for (i = 0 ;; i++)
	{
		if (!i)
			temp = strtok(path, ":");
		else
			temp = strtok(NULL, ":");
		if (!temp)
			break;
		printf("%s\n", temp);
	}
	free(path);
	free(temp);
	return (0);
}
