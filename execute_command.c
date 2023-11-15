#include "shell.h"

 /**
 *execute_command: Execute a command in a new proces.
 * execute_command(char **command) - a command in new pro.
 *
 * This function takes an array of strings representing
 *
 * @param command An array of strings representing
 * the command and its arguments.
 * @return Returns 1 if the command was executed.
 */

int execute_command(char **command)
{
	pid_t pid;
	int status;
	pid_t wpid;
	(void)wpid;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(command[0], command) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
