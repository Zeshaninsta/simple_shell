#include "shell.h"

/* Function prototypes */
void fork_cmd(info_t *info);
void find_cmd(info_t *info);

/* ... (other function prototypes) */

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av);

/* ... (other function implementations) */

/**
 * fork_cmd - forks an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error creating child process");
        return;
    }

    if (child_pid == 0)
    {
        if (execve(info->path, info->argv, get_environ(info)) == -1)
        {
            free_info(info, 1);
            if (errno == EACCES)
                exit(PERMISSION_DENIED);
            exit(EXEC_FAILURE);
        }
    }
    else
    {
        int status;
        if (waitpid(child_pid, &status, 0) == -1)
        {
            perror("Error waiting for child process");
            return;
        }

        if (WIFEXITED(status))
        {
            info->status = WEXITSTATUS(status);
            if (info->status == PERMISSION_DENIED)
                print_error(info, "Permission denied\n");
        }
    }
}

