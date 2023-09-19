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
/* Child process*/
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
/*Parent process*/
int status;
waitpid(child_pid, &status, 0);
}
}

void first_display(void)
{
	char display[] = "EBASH SHELL © ";
	write(STDOUT_FILENO, display, sizeof(display) - 1);
}
