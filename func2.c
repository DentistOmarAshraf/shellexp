#include "main.h"

void free_grid(char **argv)
{
	int i;

		for (i = 0 ; argv[i] ; i++)
			free(argv[i]);
		free(argv);
}
/**
 * free_ptr - is to free pointer and set it to NULL
 * I made this function to shortining the main
 * @ptr: pointer of pointer to str
 * Return: void
 */
void free_ptr(char **ptr)
{
	if (!(ptr && *ptr))
		return;
	free(*ptr);
	*ptr = NULL;
}
