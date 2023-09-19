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
