/*
* SIMPLE SHELL PROJECT.
* Authors : Ikejiaku Uchenna Timothy and Emmanuel Mumo
* Write - used to display the prompt message
* while loop - creates an infinite loop that keeps asking the user fora prompt
* Main - takes command executes them.
* ctrl D - exits shell
*
* Return (0) - Always success
*/

#include "shell_functions.h"

int main(void)
{
	char command[CMD_LENGTH];

	while (8)
{
	first_display();

ssize_t bytes = read(STDIN_FILENO, command, sizeof(command));

if (bytes == -1)
{
	perror("Read failed");
	exit(EXIT_FAILURE);
}

if (bytes == 0)
{
	write(STDOUT_FILENO, "\nGoodbye!\n", sizeof("\nGoodbye!\n"));
	break;  /* Exit the shell on EOF (Ctrl+D)*/
}

command[bytes - 1] = '\0';

if (strlen(command) > 0)
{
execute_command(command);
}
}

return 0;
}

