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
	int status;
	char *input;

	display_prompt();

	do {
		input = read_line();

		if (input == NULL)
{
			/* Handle end-of-file condition (Ctrl+D) */
			printf("\n");
			break;
		}
		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Execute the command */
		status = execute_command(parse_command(input));

		/* Free the allocated memory for input */
		free(input);
	} while (status);

	return (EXIT_SUCCESS);
}
