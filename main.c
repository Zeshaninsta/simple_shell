#include "shell.h"

/**
 * main - Entry point for the simple shell.
 *
 * This function displays a prompt, waits for the user to type a command,
 * and executes the command. The prompt is displayed again after each command.
 *
 * Return: Returns EXIT_SUCCESS on successful completion
 */
int main(void)
{
	char *input;
	int status;

	do {
		display_prompt();
		input = read_line();
		if (input == NULL || *input == '\0')
{
			printf("\n");
			break;
		}

		/* Execute the command */
		status = execute_command(parse_command(input));

		/* Free the allocated memory for input */
		free(input);
	} while (status);

	return (EXIT_SUCCESS);
}

