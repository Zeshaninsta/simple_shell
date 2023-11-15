#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/**
 * free_memory - Frees the memory allocated for an array of strings.
 *
 * This function takes an array of strings and frees the memory
 * allocated for each string and the array itself.
 *
 * @args: An array of strings.
 */
void free_memory(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
