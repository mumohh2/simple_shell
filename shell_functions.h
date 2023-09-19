#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define CMD_LENGTH 5000

void first_display(void);
void execute_command(const char *command);
void execute_command_with_args(const char *command, char *args[]);


#endif
