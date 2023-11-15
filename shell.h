#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Function declarations */
/**
 * Execute a command in a new process.
 *
 * This function takes an array of strings representing
 * the command and its arguments, forks a new process, and executes the command.
 *
 * @param command An array of strings representing
 *                the command and its arguments.
 * @return Returns 1 if the command was executed successfully, otherwise 0.
 */
int execute_command(char **command);

/* Function to parse the command entered by the user */
/**
 * parse_command - Tokenizes the input string into an array of tokens.
 *
 * This function takes a command input as a string and tokenizes it
 * based on specified delimiters.
 */
char **parse_command(char *input);

/* Function to free the memory allocated for command parsing */
void free_memory(char **args);

/* Function to display the shell prompt */
void display_prompt(void);

/* Function to read a line from the user */
char *read_line(void);

#endif /* SHELL_H */

