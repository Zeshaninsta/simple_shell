#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Function declarations */
int execute_command(char **command);

/* Function to parse the command entered by the user */
char **parse_command(char *input);

/* Function to free the memory allocated for command parsing */
void free_memory(char **args);

/* Function to display the shell prompt */
void display_prompt(void);

/* Function to read a line from the user */
char *read_line(void);

#endif /* SHELL_H */
