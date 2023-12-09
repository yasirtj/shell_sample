#include "main.h"

/**
 * execute_command - executes the user input command
 * @argv: pointer to null termincated array of char
 * Return: Sucess
*/
void execute_command(char **argv)
{
	char *string_cmd = NULL;

	if (argv != NULL)
	{
		string_cmd = argv[0];
		if (execve(string_cmd, argv, NULL) == -1)
		{
			custom_exit(1, "Command not found!\n");
		};
	}
}
