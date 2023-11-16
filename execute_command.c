#include "custom_shell.h"

/**
 * execute_command - Executes a command in the shell
 * @input: Contains the command and arguments in the input string
 * Return: Nothing
 */
void execute_command(char *input)
{
		int status;
		pid_t pid;
		int arg_counter;
		char *custom_command;
		char *args[200];
		custom_command = strtok(input, " ");
		args[0] = custom_command;
		arg_counter  = 1;
		while (arg_counter < 199)
		{
				args[arg_counter] = strtok(NULL, " ");
				if (args[arg_counter] == NULL)
				{
						break;
				}
				arg_counter++;
		}
		args[arg_counter] = NULL;
		exit_command(args);
		env_commands(args);

		if (arg_counter > 0)
		{
				pid = create_process();
				if (pid == 0)
				{
						search_command_in_path(args);
				}
				else if (pid == -1)
				{
						perror("fork");
						exit(1);
				}
				else
				{
						waitpid(pid, &status, 0);
				}
		}
}

