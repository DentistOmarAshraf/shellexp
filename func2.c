#include "main.h"
/**
 * free_grid - function to free tokens
 * @argv: pointer of pointer
 * Return: NONE
 */

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
/**
 * free_all - function to free
 * it use both previous function
 * @ptr: pointer of pointer to str
 * @argv: array of pointer to str
 * Return: NONE
 */
void free_all(char **ptr, char **argv)
{
	free_ptr(ptr);
	free_grid(argv);
}
