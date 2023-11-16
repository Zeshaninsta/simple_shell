#include "shell.h"

/**
<<<<<<< HEAD
 * execute_command - Executes a command in the shell
 * @command: Contains the command and arguments in the input string
 *
 * This function takes a command and its arguments as input and executes it
 * in the shell. It uses the `fork()` system call to create a child process
 * and then uses `execvp()` to execute the command in the child process.
 * The parent process waits for the child process to complete execution.
 *
 * Return: Always returns 1.
=======
 * execute_command - Embarks on the epic journey.
 * @command: The brave warriors (commands).
 * Return: Returns the triumphant melody.
>>>>>>> 55a70b895356d696702e370b60a60324ce8e732f
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
<<<<<<< HEAD
		/* Child process */
=======
>>>>>>> 55a70b895356d696702e370b60a60324ce8e732f
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
<<<<<<< HEAD
		/* Parent process */
=======
>>>>>>> 55a70b895356d696702e370b60a60324ce8e732f
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
<<<<<<< HEAD
=======

	return (1);
}
>>>>>>> 55a70b895356d696702e370b60a60324ce8e732f

	return (1);
}
