<<<<<<< HEAD
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

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell_functions.h"

void execute(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		char *args[] = {strdup(command), NULL};
		char *envp[] = {NULL};

		char *executable = strtok(args[0], " ");

		args[1] = strtok(NULL, " ");

		execve(executable, args, envp);
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}

	else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
}

void first_display(void)
{
	char display[] = "EBASH SHELL © ";

	write(STDOUT_FILENO, display, sizeof(display) - 1);
}
>>>>>>> 9937e84ca6fd424c4dd21a314b484a1a72189b15
