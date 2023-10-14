#include "main.h"

void free_grid(char **argv)
{
	int i;

		for (i = 0 ; argv[i] ; i++)
			free(argv[i]);
		free(argv);
}
void free_ptr(char **ptr)
{
	if (!(*ptr && ptr))
		return;
	free(*ptr);
}
