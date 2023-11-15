#include "shell.h"

#define TOKEN_BUFFER_SIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"

/**
 * parse_command - Tokenizes the input string into an array of tokens.
 *
 * This function takes a command input as a string and tokenizes it
 * based on specified delimiters.
 *
 * @input: The command input string to be tokenized.
 *
 * Return: An array of tokens.
 */

char **parse_command(char *input)
{
	int buffer_size = TOKEN_BUFFER_SIZE, position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("shell");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer_size)
		{
			buffer_size += TOKEN_BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				perror("shell");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}
