#include "shell_header.h"

/**
 * main - main function
 * Return: Success
*/

int main(void)
{
	char *user_input = NULL;
	/* char *delimeter = " "; */
	/* char **cmd = NULL;*/
	/* size_t i; */
	size_t cmd_size = 0;

	/*char **argv = malloc(sizeof(char *) * (cmd_size + 1)); */

	for (;;)
	{
		if (isatty(STDIN_FILENO))
		{
			view_prompt();
			write(1, "$ ", 2);
		}
		else
		{
			view_prompt();
		}
		read_user_input(user_input, cmd_size);
		free(user_input);
	}
	return (0);
}
