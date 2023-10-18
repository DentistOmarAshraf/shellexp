#include "main.h"
/**
 * chkatt - helper function check if the prog is connected to terminal
 * @str: pointer of str
 * Return: NONE
 */

void chkatt(char *str)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * getcmnd - helper function to get user input
 * and save it pointer
 * @str: pointer of pointer to str
 * @n: pointer to size_t
 * Return: none
 */
void getcmnd(char **str, size_t *n)
{
	if (getline(str, n, stdin) == -1 || _strcmp(*str, "exit\n"))
	{
		free_ptr(str);
		exit(0);
	}
}
/**
 * inpmod - helper function change the last /n
 * @s: pointer of pointer
 * Return: none
 */
void inpmod(char **s)
{
	int len;

	len = _strlen(*s);
	if ((*s)[len - 1] == '\n')
		(*s)[len - 1] = '\0';
}
