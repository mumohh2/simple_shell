#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CMD_LENGTH 5000

/**
* SIMPLE SHELL PROJECT.
* Authors : Ikejiaku Uchenna Timothy and Emmanuel Mumo
* Write - used to display the prompt/message
* while loop - creates an infinite
* loop that keeps asking the user for a prompt
*
* Main - takes command executes them.
*
* ctrl D - exits shell
*
* Return (0) - Always success
*
*
*/
void first_display(void)
{
char display[] = "EBASH SHELL ©";
write(STDOUT_FILENO, display, sizeof(display) - 1);
}

void execute(const char *execute_command);

int main(void)
{
char execute_command(CMD_LENGTH)
}
while (7)
{
	first_display();
	ssize_t bytes = read(STDIN_FILENO, execute_command, sizeof(execute_command));

	if (bytes == -1)
	{
		perror("Read failed");
		exit(EXIT_FAILURE);
	}
if (bytes == 0)
{	write(STDOUT_FILENO, "\nbye!\n", sizeof("\nbye!\n"));
	break;
	/*Exit the shell on EOF (Ctrl+D)*/
}
execute_command[bytes - 1] = '\0';

if (strlen(execute_command) > 0)
{
	execute(execute_command);
}
return (0);
}

void execute(const char *execute_command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
	perror("Fork failed");
	exit(EXIT_FAILURE);
	}

	else if (child_pid == 0)
	{
		/*Child process*/
		char *args[] = {NULL};
		char *envp[] = {NULL};

		execve(execute_command, args, envp);
		/* If execve returns, an error occurred*/
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process*/
		int status;

		waitpid(child_pid, &status, 0);
	}
