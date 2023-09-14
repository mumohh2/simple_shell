#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 256

int main(void)
{
	char command(MAX_COMMAND_LENGTH);

	while (1)
	{
		printf('simple_shell> ');
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nshell exited, \n");
			break;
		}
		command[strlen(command) - 1] = '\0';

		if (strlen(command) > 0)
		{
			if (fork() == 0)
			{
				if (execlp(command, command, (char *)NULL) == -1)
				{
					perror("Error");
				}
				exit(0);
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
