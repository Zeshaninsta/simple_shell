#include "shell.h"

/**
 * execute_command - Embarks on the epic journey.
 * @command: The brave warriors (commands).
 * Return: Returns the triumphant melody.
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
        /*child process*/
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
        /*parent process*/
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}