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
