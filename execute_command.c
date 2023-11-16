#include "shell.h"

/**
 * execute_command - Executes a command in the shell
 * @command: Contains the command and arguments in the input string
 *
 * This function takes a command and its arguments as input and executes it
 * in the shell. It uses the `fork()` system call to create a child process
 * and then uses `execvp()` to execute the command in the child process.
 * The parent process waits for the child process to complete execution.
 *
 * Return: Always returns 1.
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
