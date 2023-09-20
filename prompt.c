#include "shell.h"

/**
 * prompt - It prints the shell prompt to stdin stream
 * Return: void
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
