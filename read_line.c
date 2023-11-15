#include "shell.h"

/**
 * read_line - Read a line from the user.
 *
 * This function reads a line of input from the user
 * using the getline function.
 *
 * Return: A pointer to the string containing the user's input.
 * The caller is responsible for freeing the allocated memory.
 */
char *read_line(void)
{
	 char *line = NULL;
	size_t bufsize = 0;

	 getline(&line, &bufsize, stdin);
	return (line);
}
