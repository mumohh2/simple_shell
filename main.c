#include "shell_functions.h"

int main(void)
{
	char command[CMD_LENGTH];

while (7)
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
	break;  
	/* Exit the shell on EOF (Ctrl+D)*/
}

command[bytes - 1] = '\0';

<<<<<<< HEAD
if (strlen(command) > 0)
{
	execute(command);
}
}
return 0;
=======
		waitpid(child_pid, &status, 0);
	}
>>>>>>> 777a7176c7ae280753ff3fa3f0bdd6078c2f0c51
}
