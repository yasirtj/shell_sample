#include "shell_header.h"

/**
 * execute_command - executes the user input command
 * @argv: pointer to null termincated array of char
 * Return: Sucess
*/
void execute_command(char **argv)
{
	char *string_cmd = NULL, *cmd_with_path = NULL;
	pid_t pid;
	int status = 0;

	if (argv != NULL)
	{
		string_cmd = argv[0];
		cmd_with_path = cmd_locater(string_cmd);
		if (cmd_with_path != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				custom_exit(1, "Failed to create a child process\n");
			}
			if (pid == 0)
			{
				if (execve(cmd_with_path, argv, NULL) == -1)
				{
					custom_exit(1, "Command not found!\n");
				}
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		else
		{
			custom_exit(1, "Command not found!\n");
		}
	}
}
