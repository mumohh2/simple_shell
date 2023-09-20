#include "shell.h"

/**
 * prompt - display the shell prompt
 * Return: void
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$", 2);
}
